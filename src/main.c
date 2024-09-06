#include <stdio.h>

#define NAME "Bilgehan"

/* Function Declaration */
void sayHi(char name[] /*String*/ );

int main() {
    sayHi(NAME);
    return 0;
}

void sayHi(char name[]) {
    printf("Hi, %s!\n", name);
}