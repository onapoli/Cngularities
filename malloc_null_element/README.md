## DANGEROUS NULL ELEMENT ASSIGNMENT

This is an example of a dangerous way of increasing the size passed to malloc in order to add space for a null element.

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
