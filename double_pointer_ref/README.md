## Unintended Dereference Of A Double Pointer

This is an example of a mistake I made trying to dereference a double char pointer (char **) inside a function that will allocate a copy of another string to it.

#### Wanted example compilation in Unix

```shell
gcc -Wall -Wextra -Werror main.c wanted.c -o wanted_example
```

OR

```shell
clang -Wall -Wextra -Werror main.c wanted.c -o wanted_example
```

#### Not Wanted example compilation in Unix

```shell
gcc -Wall -Wextra -Werror main.c not_wanted.c -o not_wanted_example
```

OR

```shell
clang -Wall -Wextra -Werror main.c not_wanted.c -o not_wanted_example
```

#### Wanted example execution in Unix

```shell
./wanted_example
```

#### Not wanted example execution in Unix

```shell
./not_wanted_example
```
