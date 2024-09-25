Monty Bytecode Interpreter
Monty 0.98 is a stack-based scripting language, inspired by Python, that is compiled into Monty Byte Codes. This project implements an interpreter for Monty ByteCodes, which allows manipulation of a unique stack through various opcodes.

Table of Contents
Description
Monty Bytecode Files
The Monty Program
Usage
Error Handling
Supported Opcodes
Memory Management
Contributing
Author(s)
License
Description
Monty 0.98 is a scripting language built around a stack structure, providing specific instructions for stack manipulation. This project aims to create an interpreter that reads Monty ByteCodes and performs the appropriate operations on a stack.

Monty Bytecode Files
Monty bytecode files typically have a .m extension, though it is not a strict requirement. Each line of a bytecode file contains a single instruction, which may include an opcode and its argument. The interpreter processes one instruction per line.

Instructions can be preceded or followed by any number of spaces.
Lines can be empty or consist of comments (text after the instruction or blank spaces are ignored).
Bytecode files can contain multiple instructions that manipulate the stack.
Example Bytecode File (bytecodes/000.m):
bash
Copy code
push 0
push 1
push 2
  push 3
                   pall
push 4
    push 5
      push    6
pall
The above bytecode file will push values onto the stack and then print the stack contents using the pall opcode.

The Monty Program
The Monty interpreter reads Monty ByteCode files, interprets the instructions, and executes them. It processes the bytecode file line-by-line and interacts with a stack to perform the following operations:

Executes each line of the bytecode file.
Stops if it encounters an error or reaches the end of the file.
Prints error messages for invalid instructions or memory allocation failures.

Usage
All the files are compiled in the following form:

 gcc -Wall -Werror -Wextra -pedantic *.c -o monty.

To run the program:

 ./monty bytecode_file
Where <file> is the path to the Monty ByteCode file. Example:

bash
Copy code
./monty bytecodes/000.m
Example Usage:
bash
Copy code
julien@ubuntu:~/monty$ ./monty bytecodes/000.m
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
Command-Line Arguments:
If no file is provided, or more than one argument is passed, the program prints the error message USAGE: monty file and exits with EXIT_FAILURE.
If the file cannot be opened, it prints Error: Can't open file <file> and exits with EXIT_FAILURE.
Error Handling
The Monty interpreter handles the following errors:

No file provided or multiple arguments: Prints USAGE: monty file and exits.
File opening failure: Prints Error: Can't open file <file> and exits.
Invalid instructions: Prints L<line_number>: unknown instruction <opcode> and exits. Line numbers start from 1.
Memory allocation failure: If malloc fails, it prints Error: malloc failed and exits.

Available operation codes:

Opcode	Description
push	Pushes an element to the stack. e.g (push 1 # pushes 1 into the stack)
pall	Prints all the values on the stack, starting from the to of the stack.
pint	Prints the value at the top of the stack.
pop	Removes the to element of the stack.
swap	Swaps the top to elements of the stack.
add	Adds the top two elements of the stack. The result is then stored in the second node, and the first node is removed.
nop	This opcode does not do anything.
sub	Subtracts the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.
div	Divides the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.
mul	Multiplies the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.
mod	Computes the remainder of the top two elements of the stack from the second top element. The result is then stored in the second node, and the first node is removed.
#	When the first non-space of a line is a # the line will be trated as a comment.
pchar	Prints the integer stored in the top of the stack as its ascii value representation.
pstr	Prints the integers stored in the stack as their ascii value representation. It stops printing when the value is 0, when the stack is over and when the value of the element is a non-ascii value.
rotl	Rotates the top of the stack to the bottom of the stack.
rotr	Rotates the bottom of the stack to the top of the stack.
stack	This is the default behavior. Sets the format of the data into a stack (LIFO).
queue	Sets the format of the data into a queue (FIFO).

Memory Management
All dynamic memory allocation is handled using malloc.
It is essential to free all allocated memory to prevent leaks.
The Monty program does not use functions like realloc or calloc.

Contributing
Contributions are welcome! Please follow these steps:

Fork the repository.
Create a new feature branch (git checkout -b feature-branch).
Commit your changes (git commit -m 'Add new feature').
Push to the branch (git push origin feature-branch).
Open a pull request for review.

AUTHOR(s)
This program was written by mostafa El-Sharkawy and Martain George

License
This project is licensed under the MIT License - see the LICENSE file for details.
