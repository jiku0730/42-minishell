*This project has been created as part of the 42 curriculum by surayama, kjikuhar.*

# minishell

## Description

Minishell is a simplified shell implementation written in C, inspired by bash. The goal of this project is to understand how a real shell works by building one from scratch: parsing user input, managing environment variables, handling redirections and pipes, and executing commands.

Key features include:

- Interactive prompt with command history (GNU readline)
- Tokenization and parsing of shell commands into an AST (Abstract Syntax Tree)
- Pipes (`|`) and redirections (`<`, `>`, `>>`, `<<`)
- Environment variable expansion (`$VAR`, `$?`)
- Quote handling (single and double quotes)
- Here-documents (`<<`)
- Built-in commands: `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- Signal handling (`Ctrl+C`, `Ctrl+D`, `Ctrl+\`)

## Instructions

### Prerequisites

- GCC, Make, GNU readline library

### Build and Run

```bash
# Build the project
make

# Run the shell
./minishell
```

### Other Make Targets

| Command         | Description                                      |
|-----------------|--------------------------------------------------|
| `make`          | Build the project                                |
| `make re`       | Clean rebuild                                    |
| `make clean`    | Remove object files                              |
| `make fclean`   | Remove object files and binary                   |
| `make norm`     | Run norminette style checker                     |
| `make valgrind` | Rebuild and run with valgrind for leak detection  |
| `make test`     | Run norminette + valgrind                        |

### Usage Examples

```
$ ./minishell
minishell$ echo hello world
hello world
minishell$ ls -la | grep Makefile
-rw-r--r--  1 user  staff  2048 Apr 10 12:00 Makefile
minishell$ export FOO=bar
minishell$ echo $FOO
bar
minishell$ cat << EOF
> hello
> world
> EOF
hello
world
minishell$ exit
```

## Architecture

The shell follows an interpreter pipeline:

```
Input -> tokenize() -> heredoc() -> parse() -> AST -> expand() -> execute
```

1. **Tokenizer** -- State-machine-based lexer that splits input into tokens at operator, space, and quote boundaries.
2. **Heredoc** -- Processes here-document redirections before parsing.
3. **Parser** -- Recursive descent parser that produces a binary AST with `PIPE`, `AND`, `OR`, `SUBSHELL` (internal) and `CMD` (leaf) nodes.
4. **Expand & Execute** -- Walks the AST and, for each command, applies expansion (tilde, `$?`, parameter, wildcard, quote removal) then executes via `fork`/`execve`.

## Resources

- [The Open Group Base Specifications -- Shell Command Language](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)
- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [Writing Your Own Shell (42 tutorial)](https://harm-smits.github.io/42docs/projects/minishell)
- [GNU Readline Library Documentation](https://tiswww.case.edu/php/chet/readline/rltop.html)

### Use of AI

AI (Claude Code by Anthropic) was used as a development assistant for the following tasks:

- Code review and debugging assistance
- Generating boilerplate code and Makefile configurations
