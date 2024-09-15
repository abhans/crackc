#include <stdio.h>

/*Constant Definitions*/

#define NAME "Bilgehan"
#define BLOCK '|'

/*Enums*/

enum Type {
    INT,
    FLOAT,
    DOUBLE,
    CHAR,
    LONG,
    SHORT
}

/*Declarations*/

void sayHi(char name[] /*String*/ );
void printBlock(char block, int nrow, int ncol);
void printByte(int type);


int main() {
    // sayHi(NAME);
    // printBlock(BLOCK, 3, 8);
    printByte(DOUBLE);
    return 0;
}

/*Function Definitions*/

/**
 * --------------------
 * 
 * Takes a string (character array) as an argument and prints a greeting message
 * that includes the provided name. The message is printed in the format: "Hi, <name>!".
 * 
 * @param name: A string (`char[]`) representing the name to be included in the greeting.
 */
void sayHi(char name[]) {
    printf("Hi, %s!\n", name);
}

/**
 * --------------------
 * 
 * Prints a block of characters with specified dimensions.
 *
 * @param block: The character to be printed.
 * @param nrow: The number of rows in the block.
 * @param ncol: The number of columns in the block.
 */
void printBlock(char block, int nrow, int ncol) {
    for (int row = 0; row < nrow; row++) {
        for (int col = 0; col < ncol; col++) {
            printf("%c", block);
        }
        printf("\n");
    }
}

/**
 * Prints the size (in bytes) of the specified data type.
 * 
 * This function takes an enumeration component from `Type` representing a data type and prints 
 * its corresponding size in bytes. The data types covered are `int`, `float`, `double`, 
 * `char`, `long`, and `short`.
 * 
 ```C
 printByte(Type[0]);
 >>> "Size: 4 bytes"
 ```
 */
void printByte(int type) {
    const size_t sizes[] = {
        sizeof(int),
        sizeof(float),
        sizeof(double),
        sizeof(char),
        sizeof(long),
        sizeof(short)
    };

    printf("Size: %zu bytes\n", sizes[type]);
}