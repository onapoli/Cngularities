## Pointer Arithmetic Inside String Traversing Loop

I needed to extract substrings from a string each time a specific character appeared.

Before writing any code, a colleague told me that pointer arithmetic could be useful for that case. What I was going to do before the suggestion was counter operations, and never thought of pointer arithmetic, so I thought it would be cool to try a new approach.

After using pointer arithmetic incorrectly, I ended up changing the approach to the first one that I had in mind, because I could not realise what I was doing wrong. It was a pitty, because the code would have been shorter, and easier to interpret.

I know the problem had to do with performing pointer arithmetic incorrectly inside a loop, because after the first iteration the content of the pointers was unexpected. If I manage to recreate the situation described, I will add it here. Meanwhile, here is a working pointer arithmetic example inside a loop.

#### Example compilation in Unix

```shell
gcc -Wall -Wextra -Werror main.c -o example
```

#### Example execution in Unix

```shell
./example
```
