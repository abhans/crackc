# Chapter 1 : A Tutorial Introduction

General purpose programming language

- **UNIX** systems (mostly written in C)
- Used to be called **system programming language**

Provides various data types  (pointers, array, structures, stacks etc.)

```plain
Pointers provide machine independent address arithmetic.
```

- C provides fundamental control flow (using `if-else`,`switch`, `break`, `for-while` etc.)

- Usage of **functions** to create automated workflows

- Low-level language (closer to hardware)

## Writing the First Program

Here’s a simple C program that prints "Hello, World!" to the console:

```c
#include <stdio.h>

int main(void) {
    printf("Hello, world!\n");
    return 0;
}
```

- `#include <stdio.h>`: This line tells the compiler to include the standard input/output library, which provides functions like `printf`.
- `int main() { ... }`: The main function is the **entry point of a C program**. The code inside this function is executed when the program runs.
- `printf("Hello, World!\n");`: This line prints the string "Hello, World!" to the console. The `\n` is a newline character, which moves the cursor to the next line after printing.
- `return 0;`: This line ends the main function and returns `0` to the operating system, indicating that **the program executed successfully**.

This program can be compiled with `gcc` as given below:

```bash
gcc hello.c -o hello
./hello
```

- `gcc` is the **GNU Compiler Collection**, a powerful tool used to compile C programs.
- `hello.c` is the source file.
- `-o hello` specifies the output file name (in this case, `hello`).

The output can be seen in the terminal as below:

```plain
>>> Hello, world!
```
