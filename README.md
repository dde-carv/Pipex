# Pipex

Pipex is a C project that replicates the UNIX shell pipeline behavior by executing a sequence of commands, connecting the output of each command to the input of the next using pipes. Focusing on process creation, inter-process communication, and file descriptor management.

## Features

- Executes two or more shell commands in sequence, piping the output of each to the next.
- Handles redirection of input and output files.
- Supports the "here document" (`here_doc`) feature for multi-line stdin input (bonus).
- Robust error management with descriptive messages.
- Modular codebase using custom linked list structures for command management.

## Usage

### Basic Syntax

```bash
./pipex file1 "cmd1" "cmd2" file2
```

This command will execute:
```bash
< file1 cmd1 | cmd2 > file2
```
- `file1`: Input file.
- `cmd1`, `cmd2`: Shell commands with arguments in quotes.
- `file2`: Output file (created or truncated).

### Bonus: Here Document

```bash
./pipex here_doc LIMITER "cmd1" "cmd2" file
```
This will:
- Read from stdin until `LIMITER` is encountered,
- Pipe through `cmd1` and `cmd2`,
- Write the output to `file`.

### Example

```bash
./pipex infile "grep hello" "wc -l" outfile
```

## Build Instructions

1. **Clone the repository**
    ```bash
    git clone https://github.com/dde-carv/Pipex.git
    cd Pipex
    ```

2. **Build the project**
    ```bash
    make
    ```
    - For bonus (here_doc support):
      ```bash
      make bonus
      ```

## Project Structure

- `inc/pipex.h` — Header file with all structure and function declarations.
- `src/` — Main source files for required features.
- `src/pipex_utils/` — Utility functions for pipes, paths, and memory management.
- `src_b/bonus_ppx/` — Bonus files including here_doc logic.
- `libft/` — Custom C library (dependency).

## Dependencies

- Standard C libraries.
- Custom `libft` (automatically built with Makefile).

---
