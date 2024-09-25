<h1>Monty Bytecode Interpreter</h1>

<p>Monty 0.98 is a stack-based scripting language, inspired by Python, that is compiled into Monty Byte Codes. This project implements an interpreter for Monty ByteCodes, which allows manipulation of a unique stack through various opcodes.</p>

<h2>Table of Contents</h2>
<ul>
  <li><a >Description</a></li>
  <li><a >Monty Bytecode Files</a></li>
  <li><a >The Monty Program</a></li>
  <li><a >Usage</a></li>
  <li><a >Error Handling</a></li>
  <li><a >Supported Opcodes</a></li>
  <li><a >Memory Management</a></li>
  <li><a >Contributing</a></li>
  <li><a >Author(s)</a></li>
  <li><a >License</a></li>
</ul>

<h2 id="description">Description</h2>
<p>Monty 0.98 is a scripting language built around a stack structure, providing specific instructions for stack manipulation. This project aims to create an interpreter that reads Monty ByteCodes and performs the appropriate operations on a stack.</p>

<h2 id="monty-bytecode-files">Monty Bytecode Files</h2>
<p>Monty bytecode files typically have a <code>.m</code> extension, though it is not a strict requirement. Each line of a bytecode file contains a single instruction, which may include an opcode and its argument. The interpreter processes one instruction per line.</p>
<ul>
  <li>Instructions can be preceded or followed by any number of spaces.</li>
  <li>Lines can be empty or consist of comments (text after the instruction or blank spaces are ignored).</li>
  <li>Bytecode files can contain multiple instructions that manipulate the stack.</li>
</ul>

<h3>Example Bytecode File (<code>bytecodes/000.m</code>):</h3>
<pre><code>
push 0
push 1
push 2
  push 3
                   pall
push 4
    push 5
      push    6
pall
</code></pre>
<p>The above bytecode file will push values onto the stack and then print the stack contents using the <code>pall</code> opcode.</p>

<h2 id="the-monty-program">The Monty Program</h2>
<p>The Monty interpreter reads Monty ByteCode files, interprets the instructions, and executes them. It processes the bytecode file line-by-line and interacts with a stack to perform the following operations:</p>
<ul>
  <li>Executes each line of the bytecode file.</li>
  <li>Stops if it encounters an error or reaches the end of the file.</li>
  <li>Prints error messages for invalid instructions or memory allocation failures.</li>
</ul>

<h2 id="usage">Usage</h2>
<p>All the files are compiled in the following form:</p>
<pre><code>gcc -Wall -Werror -Wextra -pedantic *.c -o monty</code></pre>
<p>To run the program:</p>
<pre><code>./monty bytecode_file</code></pre>
<p>Where <code>bytecode_file</code> is the path to the Monty ByteCode file. Example:</p>
<pre><code>./monty bytecodes/000.m</code></pre>

<h3>Example Usage:</h3>
<pre><code>
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
</code></pre>

<h3>Command-Line Arguments:</h3>
<ul>
  <li>If no file is provided, or more than one argument is passed, the program prints the error message <code>USAGE: monty file</code> and exits with <code>EXIT_FAILURE</code>.</li>
  <li>If the file cannot be opened, it prints <code>Error: Can't open file &lt;file&gt;</code> and exits with <code>EXIT_FAILURE</code>.</li>
</ul>

<h2 id="error-handling">Error Handling</h2>
<p>The Monty interpreter handles the following errors:</p>
<ul>
  <li>No file provided or multiple arguments: Prints <code>USAGE: monty file</code> and exits.</li>
  <li>File opening failure: Prints <code>Error: Can't open file &lt;file&gt;</code> and exits.</li>
  <li>Invalid instructions: Prints <code>L&lt;line_number&gt;: unknown instruction &lt;opcode&gt;</code> and exits. Line numbers start from 1.</li>
  <li>Memory allocation failure: If <code>malloc</code> fails, it prints <code>Error: malloc failed</code> and exits.</li>
</ul>

<h2 id="supported-opcodes">Available Opcodes</h2>
<table>
  <thead>
    <tr>
      <th>Opcode</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><code>push</code></td>
      <td>Pushes an element to the stack. e.g (push 1 # pushes 1 into the stack)</td>
    </tr>
    <tr>
      <td><code>pall</code></td>
      <td>Prints all the values on the stack, starting from the top.</td>
    </tr>
    <tr>
      <td><code>pint</code></td>
      <td>Prints the value at the top of the stack.</td>
    </tr>
    <tr>
      <td><code>pop</code></td>
      <td>Removes the top element of the stack.</td>
    </tr>
    <tr>
      <td><code>swap</code></td>
      <td>Swaps the top two elements of the stack.</td>
    </tr>
    <tr>
      <td><code>add</code></td>
      <td>Adds the top two elements of the stack. The result is stored in the second node, and the first node is removed.</td>
    </tr>
    <tr>
      <td><code>nop</code></td>
      <td>Does nothing.</td>
    </tr>
    <tr>
      <td><code>sub</code></td>
      <td>Subtracts the top two elements from the second top element. The result is stored in the second node, and the first node is removed.</td>
    </tr>
    <tr>
      <td><code>div</code></td>
      <td>Divides the second top element by the top element. The result is stored in the second node, and the first node is removed.</td>
    </tr>
    <tr>
      <td><code>mul</code></td>
      <td>Multiplies the top two elements. The result is stored in the second node, and the first node is removed.</td>
    </tr>
    <tr>
      <td><code>mod</code></td>
      <td>Computes the remainder of the division of the top two elements. The result is stored in the second node, and the first node is removed.</td>
    </tr>
    <tr>
      <td><code>#</code></td>
      <td>Treats the line as a comment if the first non-space character is <code>#</code>.</td>
    </tr>
    <tr>
      <td><code>pchar</code></td>
      <td>Prints the ASCII value stored at the top of the stack.</td>
    </tr>
    <tr>
      <td><code>pstr</code></td>
      <td>Prints the stack values as ASCII characters until it encounters a 0 or a non-ASCII value.</td>
    </tr>
    <tr>
      <td><code>rotl</code></td>
      <td>Rotates the top of the stack to the bottom.</td>
    </tr>
    <tr>
      <td><code>rotr</code></td>
      <td>Rotates the bottom of the stack to the top.</td>
    </tr>
    <tr>
      <td><code>stack</code></td>
      <td>Sets the format of the data into a stack (LIFO).</td>
    </tr>
    <tr>
      <td><code>queue</code></td>
      <td>Sets the format of the data into a queue (FIFO).</td>
    </tr>
  </tbody>
</table>

<h2 id="memory-management">Memory Management</h2>
<p>All dynamic memory allocation is handled using <code>malloc</code>. It is essential to free all allocated memory to prevent leaks. The Monty program does not use functions like <code>realloc</code> or
