# Monty Bytecode Interpreter

**Monty 0.98** is a stack-based scripting language inspired by Python, compiled into Monty ByteCode. This project implements an interpreter for Monty ByteCode, enabling stack manipulation through various opcodes.

## Table of Contents
- [Description](#description)
- [Monty Bytecode Files](#monty-bytecode-files)
- [The Monty Program](#the-monty-program)
- [Usage](#usage)
- [Error Handling](#error-handling)
- [Supported Opcodes](#supported-opcodes)
- [Memory Management](#memory-management)
- [Contributing](#contributing)
- [Author(s)](#authors)

---

## Description

Monty 0.98 is a scripting language built around stack-based instructions. This project implements an interpreter that reads Monty ByteCode and performs the required stack operations.

---

## Monty Bytecode Files

Monty bytecode files typically have a `.m` extension (though this is not mandatory). Each line in a bytecode file contains a single instruction, which may include an opcode and its argument. The interpreter processes each instruction line-by-line.

- Instructions can be preceded or followed by spaces.
- Lines can be empty or include comments (text after `#` is ignored).
- Bytecode files contain instructions to manipulate the stack.

### Example Bytecode File (`bytecodes/000.m`):
```m
push 0
push 1
push 2
  push 3
                   pall
push 4
    push 5
      push    6
pall
```
This file pushes values onto the stack and prints them using the `pall` opcode.

---

## The Monty Program

The Monty interpreter reads Monty ByteCode files, interprets instructions, and executes them line-by-line:

- Each instruction is executed sequentially.
- The program halts on errors or when reaching the end of the file.
- Error messages are displayed for invalid instructions or memory allocation failures.

---

## Usage

**To compile all source files:**

```
gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
**To run the program:**

```
./monty <bytecode_file>
```
Where `<bytecode_file>` is the path to the Monty ByteCode file.

**Example:**

```
./monty bytecodes/000.m
```

**Example Output:**

```
3
2
1
0
6
5
4
3
2
1
0
```
**Command-Line Arguments:**
If no file is provided or more than one argument is passed, the program outputs:
```
USAGE: monty file
```
and exits with `EXIT_FAILURE`.
If the file cannot be opened, it outputs:
```
Error: Can't open file <file>
```
and exits with `EXIT_FAILURE`.

---

## Error Handling

The Monty interpreter handles the following errors:

- **No file or multiple arguments:** Outputs `USAGE: monty file` and exits.
- **File cannot be opened:** Outputs `Error: Can't open file <file>` and exits.
- **Invalid instructions:** Outputs `L<line_number>: unknown instruction <opcode>` and exits. Line numbers start from 1.
- **Memory allocation failure:** Outputs `Error: malloc failed` and exits.

---

## Supported Opcodes

| Opcode | Description                                                                                               |
|--------|-----------------------------------------------------------------------------------------------------------|
| `push`   | Pushes an element to the stack (e.g., push 1 adds 1 to the stack).                                      |
| `pall`   | Prints all values in the stack, starting from the top.                                                  |
| `pint`   | Prints the value at the top of the stack.                                                                |
| `pop`    | Removes the top element of the stack.                                                                    |
| `swap`   | Swaps the top two elements of the stack.                                                                 |
| `add`    | Adds the top two elements; result stored in the second node, and the first node is removed.              |
| `sub`    | Subtracts the top two elements; result stored in the second node, and the first node is removed.         |
| `div`    | Divides the top two elements; result stored in the second node, and the first node is removed.           |
| `mul`    | Multiplies the top two elements; result stored in the second node, and the first node is removed.        |
| `mod`    | Computes the remainder of the top two elements; result stored in the second node, and the first node is removed. |
| `nop`    | Does nothing.                                                                                             |
| `#`      | Marks a comment line, ignored by the interpreter.                                                        |
| `pchar`  | Prints the ASCII value of the integer at the top of the stack.                                           |
| `pstr`   | Prints the ASCII values of the integers in the stack until a non-ASCII value or 0 is encountered.       |
| `rotl`   | Rotates the top element of the stack to the bottom.                                                      |
| `rotr`   | Rotates the bottom element of the stack to the top.                                                      |
| `stack`  | Sets data format to stack (LIFO, default behavior).                                                      |
| `queue`  | Sets data format to queue (FIFO).                                                                         |

---

## Memory Management

All dynamic memory is allocated using `malloc`.  
To avoid memory leaks, all allocated memory is freed.  
The Monty interpreter does not use `realloc` or `calloc`.

## Contributing

We welcome contributions! To contribute:

1. Fork the repository.
2. Create a feature branch:
 ```
git checkout -b feature-branch
 ```
3. Commit your changes:
 ```
git commit -m "Add new feature"
 ```
4. Push to the branch:
 ```
git push origin feature-branch
 ```
5. Open a pull request for review.

---

## Author(s)

This program was written by [Mostafa El-Sharkawy](https://github.com/M-sharkawy) and [Martain George](https://github.com/martingeorge191110).

