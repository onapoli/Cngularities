## Unnoticed Bad Pipeline Implementation

Setting up a pipe to communicate between a parent process and a child process is simple. The pipe must be created by the parent before creating the child process, that way, each process will have access to both ends of the pipe. One process will write to the pipe and the other will read from it, so each process must close the end of the pipe that it is not going to use.

Setting up a pipeline to communicate between more than two processes is a bit more complex, but if the rule of closing the end of the pipe that will not be used in each process is followed, it is still simple.

Here you have an example of what happens when the rule is not followed. I have recreated a mistake I made while implementing a pipeline for the first time while developing a minimal version of the GNU bash shell. I think is very interesting, because at first I did not realize that there was an error with the pipeline. The first pipeline test was with:

```shell
ls | grep | wc
```

And it seemed to work well, but when I was suggested to try this specific command, it did not work as expected:

```shell
cat | cat | ls
```

If that pipeline is introduced in bash, the output of the `ls` command gets printed first, because bash launches the commands' processes in parallel and the cat commands need input to start working. When the first `cat` command receives input, it writes it to the pipe that communicates it with the second `cat`, which will attempt to do the same with the pipe that communicates it with the `ls` process. But the `ls` process has already terminated and as a consequence the process of the second `cat` will be terminated by signal 13 (SIGPIPE):

> The PIPE signal is sent to a process when it attempts to write to a pipe without a process connected to the other end.

After the first input, there is still a prompt to provide more input to the first `cat`, whose process is still running because it could write without problems to the second `cat` after the first input. If a second input is provided, the process of the first `cat` will also terminate with signal 13.

Run the examples to see the difference between the two pipeline implementations.

#### Bad pipeline unnoticed test compilation and execution in Unix

```shell
make bad && ./pipeline a
```

#### Bad pipeline confirming test compilation and execution in Unix

```shell
make bad && ./pipeline b
```

#### Good pipeline first test compilation and execution in Unix

```shell
make && ./pipeline a
```

#### Good pipeline second test compilation and execution in Unix

```shell
make && ./pipeline b
```

#### Clean generated .o files and executable in Unix

```shell
make fclean
```
