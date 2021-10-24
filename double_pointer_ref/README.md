## UNINTENDED DEREFERENCE OF A DOUBLE POINTER

This is an example of a mistake I made trying to dereference a double char pointer (char **) inside a function that will allocate a copy of another string to it.

#### WANTED EXAMPLE COMPILATION IN UNIX
gcc -Wall -Wextra -Werror main.c wanted.c -o wanted_example
OR
clang -Wall -Wextra -Werror main.c wanted.c -o wanted_example

#### NOT WANTED EXAMPLE COMPILATION IN UNIX
gcc -Wall -Wextra -Werror main.c not_wanted.c -o not_wanted_example
OR
clang -Wall -Wextra -Werror main.c not_wanted.c -o not_wanted_example

#### WANTED EXAMPLE EXECUTION IN UNIX
./wanted_example

#### WANTED EXAMPLE EXECUTION IN UNIX
./not_wanted_example
