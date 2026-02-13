*This project has been created as part of the 42 curriculum by coholbur.*

# Pipex

Pipex is a project focused on learning the pipes process between two commands by simulating its behaviour.

## Description

 The program takes four arguments : two files and two shell commands, which are necessary to create the simulation environement for inter-process communication. The information is stored in the input file and is redirected to the output file, executing the Bash commands taken as arguments. \
 This project demonstrates inter-process communication using pipes and explores the Unix process model, particularly the relationship between parent and child processes.
 
## Instructions

A Makefile must be created and the program should to be compiled at the root of the repository, using :

```bash
make
```
 The project must be executed as follows:

```bash
./pipex file1 cmd1 cmd2 file2
```

### Setup

The main process is implemented in `pipex.c`, and the necessary functions and libraries are defined in `pipex.h`.

#### Helper Functions
The helper functions are implemented in `utils.c`, `utils1.c`, and `utils2.c` to handle:
- Path resolution
- Error handling
- Memory management

These functions support the execution of commands and ensure the program handles failures cleanly.

#### Reading Process

The program reads input from the file specified as `argv[1]` using `open()` and prepares it to be sent through the pipe to the first command. It opens the input file in read-only mode and checks for errors before redirecting it to standard input (`STDIN_FILENO`) using `dup2`.

#### Parent-Child Processes

The program creates two child processes using `fork()`:

1. **First child (`child_process`)**  
   - Reads from the input file  
   - Redirects output to the write end of the pipe  
   - Executes the first command (`argv[2]`)  

2. **Second child (`second_child_process`)**  
   - Reads from the read end of the pipe  
   - Redirects output to the output file (`argv[4]`)  
   - Executes the second command (`argv[3]`)  

The parent process closes unused pipe ends and waits for both child processes to finish.

#### Main Function

The `main` function handles:

- Argument validation (ensuring exactly 4 arguments)
- Pipe creation (`create_pipe`)
- Forking two child processes
- Executing the child processes
- Waiting for the children to finish
- Proper cleanup of file descriptors

## Resources

 - **Peer-to-peer learning** – was the most valuable resource; this project was developed with guidance and collaboration from other 42 students;
 - **Books** – Classic references to learn C from scratch and understand various programming notions;
 - **Tutorials and articles** – Consulted to better understand the steps in the implementation of `pipes()` process.

### AI Assistance
AI tools were used to help:
- Create diagrams and schemas to visualize how functions work and how data flows.
- Provide examples of commands to use

No AI was used to write the functions directly; all code logic and implementation are my own work and personal vision.
