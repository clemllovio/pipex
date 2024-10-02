# pipex
pipex is a project that recreates the behavior of the shell pipe operator (|) in C. It takes an input file, executes a series of commands, and writes the output to a file. This project aims to deepen understanding of processes, file descriptors, and inter-process communication in Unix-like operating systems.
## Installation
To use this program:
  1. Clone the repository:
     ```bash
     git clone https://github.com/clemllovio/pipex.git
     ```
  2. Navigate to the project directory and compile
## Usage
After compiling, you'll have a `pipex` executable. Use it as follows:
```bash
./pipex file1 cmd1 cmd2 file2
```
This is equivalent to the shell command:
```bash
< file1 cmd1 | cmd2 > file2
```
## Credits
This project was developed by Clémence Llovio as part of the curriculum at 42 School. 
