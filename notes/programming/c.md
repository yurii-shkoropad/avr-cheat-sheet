# C

## Compilation stages
Here are the typical stages in the compilation process:

- Preprocessing. The preprocessor handles tasks such as including header files, macro expansion, and conditional compilation. It produces a modified version of the original source code, known as the preprocessed code. Also it removes comments. You can get result of this stage using next command:

`$ clang -E example.c -o example.i`

- Compilation. The compiler proper translates the preprocessed code into assembly code or an intermediate representation. This stage involves lexical analysis, syntax analysis, semantic analysis, and code generation.
- Assembly. The assembler converts the assembly code into machine code or object code, which consists of binary instructions that the computer's CPU can execute.
- Linking. The linker combines the object code generated from multiple source files and resolves references between them. It produces an executable file that can be run on a computer.

## Compilers
- GCC (GNU Compiler Collection)
- Clang

## Preprocessor directive
- `#define` - directive is used to create symbolic constants and macros. Example:
```c
#define a 10
#define SQUARE(x) (x * x) // Macros should be in upper case
int b = SQUARE(a);
```

- `#include` -  directive is used for including the contents of another file (typically a header file) into your source code. Example:
```c
#include <stdlib.h>
#include "../libs/spi.c"
```

- `#if`, `#else`, `#endif`, `#elif` - conditional directive. Example:
```c
#define d 10

#if defined(d)
  printf("defined");
#else
  printf("not defined");
#endif
```

```c
#if X == Y
    // Code to include if X is equal to Y
#endif

#if VERSION >= 2
    // Code to include if the VERSION is 2 or greater
#endif

#if !defined(A)
    // Code to include if A is not defined
#endif
```

- `#ifdef`, `#ifndef` - conditional directives for check if defined or not. Next code equivalent:
```c
#if defined(MACRO_NAME)
```
```c
#ifdef MACRO_NAME
```
And:
```c
#if !defined(MACRO_NAME)
```
```c
#ifndef MACRO_NAME
```

## Keywords
- `volatile` - keyword to specify do not optimize variable. Useful with interrupts. Example: 
```c
volatile uint8_t bcdCounter = 0;
```

- `struct` - user-defined composite data type that allows you to group together variables of different data types under a single name. Example:
```c
struct Person {
    char name[50];
    int age;
    float height;
};

struct Person person1;
```
- `typedef` - keyword used to create a new data type alias. Example:
```c
typedef struct Person {
  char name[20];
  int age;
  float height;
} Person;

Person bob = {
  .name = "Bob",
  .age = 13,
  .height = 1.2
};
```

## Operators
- `&` -  address-of operator. Returns pointer to variable. Example:
```c
int a = 10;

int * aP = &a;
printf("Pointer address %p\n", aP);
```
- `*` - dereference operator. Dereferencing a pointer means accessing the value stored at the memory location pointed to by the pointer. Example:
- 
- `->` member of pointer. Operator is used to access a member of a structure or a union through a pointer.`ptrPerson->name` is equivalent to `(*ptrPerson).name`. Example: 
```c
typedef struct Pin {
  int pin;
  int port;
} Pin;

void print_port_number(Pin *pin) {
  printf("Port number = %d", pin->port);
}

Pin p1 = {10, 10};

print_port_number(&p1);
```

## Useful functions
- `snprintf` - defined in `<stdio.h>`,  formats and stores a series of characters and values in the array buffer. Useful to get string with integer.
```c
  char buffer[30];
  snprintf(buffer, sizeof(buffer), "i=%d\r\n", i);
  usart_print_string(buffer);
```
- `memcpy` - defined in `<string.h>`, copies content from source to target.
```c
int sourceArray[] = {1, 2, 3, 4, 5};
int destinationArray[5];
memcpy(destinationArray, sourceArray, 5 * sizeof(int));
```
- `itoa` - defined in `<stdlib.h>`, converts integer to string with specified radix (print number in binary for example).
```c
char buffer[10];
itoa(seconds, buffer, 2);
usart_print_string(buffer);
```

## Specifiers
| Specifier | Used for                                           |
| --------- | -------------------------------------------------- |
| %c        | a single character                                 |
| %s        | a string                                           |
| %hi       | short (signed)                                     |
| %hu       | short (unsigned)                                   |
| %Lf       | long double                                        |
| %n        | prints nothing                                     |
| %d        | a decimal integer (assumes base 10)                |
| %i        | a decimal integer (detects the base automatically) |
| %o        | an octal (base 8) integer                          |
| %x        | a hexadecimal (base 16) integer                    |
| %p        | an address (or pointer)                            |
| %f        | a floating point number for floats                 |
| %u        | int unsigned decimal                               |
| %e        | a floating point number in scientific notation     |
| %E        | a floating point number in scientific notation     |
| %%        | the % symbol                                       |
| %lu       | long int                                           |