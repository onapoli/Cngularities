## Dangerous Null Element Assignment

This is an example of a dangerous way of increasing the size passed to malloc in order to add space for a null element.

#### Wanted example compilation in Unix

```shell
gcc -Wall -Wextra -Werror main.c wanted.c -o wanted_example
```

#### Not Wanted example compilation in Unix

```shell
gcc -Wall -Wextra -Werror main.c not_wanted.c -o not_wanted_example
```

#### Wanted example execution in Unix

```shell
./wanted_example
```

#### Not wanted example execution in Unix

```shell
./not_wanted_example
```
