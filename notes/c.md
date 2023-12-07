# C

## Compilation stages
Here are the typical stages in the compilation process:

- Preprocessing. The preprocessor handles tasks such as including header files, macro expansion, and conditional compilation. It produces a modified version of the original source code, known as the preprocessed code.
- Compilation. The compiler proper translates the preprocessed code into assembly code or an intermediate representation. This stage involves lexical analysis, syntax analysis, semantic analysis, and code generation.
- Assembly. The assembler converts the assembly code into machine code or object code, which consists of binary instructions that the computer's CPU can execute.
- Linking. The linker combines the object code generated from multiple source files and resolves references between them. It produces an executable file that can be run on a computer.

## Compilers
- GCC (GNU Compiler Collection)
- Clang

## Keywords
- `volatile` - keyword to specify do not optimize variable. Useful with interrupts. Example `volatile uint8_t bcdCounter = 0;`

## Useful functions
- `snprintf` - defined in `<stdio.h>`,  formats and stores a series of characters and values in the array buffer. Useful to get string with integer. Example:
```c
  char buffer[30];
  snprintf(buffer, sizeof(buffer), "i=%d\r\n", i);
  printUSARTString(buffer);
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