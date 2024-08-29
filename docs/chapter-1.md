# Chapter 1 : A Tutorial Introduction
General purpose programming language

- **UNIX** systems (mostly written in C)
- Used to be called **system programming language**

Provides various data types  (pointers, array, structures, stacks etc.)

```
Pointers provide machine independent address arithmetic.
```

- C provides fundamental control flow (using `if-else`,`switch`, `break`, `for-while` etc.)

- Usage of **functions** to create automated workflows

- Low-level language (closer to hardware)

## Writing the First Program

First program for a programmşing language:
```[c]
#include <stdio.h>

int main(void) {
    printf("Hello, world!\n");
    return 0;
}
```

This program can be compiled with `gcc` as given below:
```[shell]
gcc hello.c -o hello
./hello
```

The output can be seen in the terminal:
```[shell]
>>> Hello, world!
```

