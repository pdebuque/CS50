# compiling

## explaining the 'make' command

"make" is not a compiler. it automates use of `clang` - c language:

```
make hello
``` 

is actually 

```
clang -o hello hello.c
```
where `-o` names the output. without it, the compiler would default to `a.out` (assembler output).

### compiling with the cs50 header

`clang -o hello hello.c` will fail if using the cs.50 library: even though `#include <cs.50>` tells the compiler the library's functions exist, the compiler cannot find the functions themselves. To get those,

```
clang -o hello hello.c -lcs50
```
`-l` tells the compiler to link in `cs50`.

`stdio` is built in, so doesn't need the `-l`.

## How does compiling actually work?

There are 4 steps:

### 1. Preprocessing
Analyzing and executing hash (#) lines. e.g., `#include <stdio.h>`. Compiler goes into the included files and copy/pastes the functions from them into the script. e.g., 

```c
#include <cs50.h>
``` 
becomes

```c
string get_string(string prompt);
int get_int(int promt);
...
...
```
### 2. Compiling
Converting the body of the script into assembly code. Instructions to move pieces in, around, and out of memory.

### 3. Assembling
Converting assembly code to machine code - the 0s and 1s ultimately read by the computer.

### 4. Linking
Combining the 0s and 1s from the script with the 0s and 1s of the various libraries/headers.

## What can go wrong?

thought experiment: what if we could decompile? reverse the process: 0s and 1s => C. (in practice, very difficult and messy: no pretty variables, function logic, etc. would come up)
- intellectual property danger
- exploit security weaknesses

# Debugging
How can we locate and fix mistakes?

simplest: use `printf` to help see what the code is doing.

next level: use <b>debugger</b>. included in vscode.
- place breakpoints: make computer stop there
- run debugger - step over breakpoints and monitor variables, output, etc.

conceptual: <b>rubber duck</b>: talking through conceptual/logical problems

# Strings and Arrays

strings are weird - unlike all other data types (int, char, etc.), strings have an indefinite number of bytes, depending on the length of the string.

strings are really just arrays of chars with an extra delimiter byte. `"Hi!"` is really `['H', 'i', '!', \0(aka NUL)]`

string functions/methods are available through `string.h`

another good library: `ctype.h`

# command-line arguments

everything after the initial command is an *argument*, which can be accessed in a program

```c
int main(int argc, string argv[])
{
  ...
}
```

note: `argv[0]` will give the first word (usually the command)

# exit codes

the `int` in `int main(void)` is because every main will give an exit code. If it works, the return int is 0. non-zeros can give error codes.

```
echo $?
```
gives the status code.

we can control exit codes with returns in the function

# cryptography
cryptography: the practice of scrambling or encrypting messages to protect its information.

plaintext, key --> | cipher | --> ciphertext