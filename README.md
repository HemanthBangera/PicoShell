# PicoShell

![PicoShell Banner](src/assets/image.png)

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/HemanthBangera/PicoShell)
[![Language](https://img.shields.io/badge/language-C-blue.svg)](https://github.com/HemanthBangera/PicoShell)
[![License](https://img.shields.io/badge/license-MIT-green.svg)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS-lightgrey.svg)](https://github.com/HemanthBangera/PicoShell)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](https://github.com/HemanthBangera/PicoShell/pulls)

A lightweight shell implementation written in C that recreates core functionality of a Unix shell. PicoShell is an educational project designed to demonstrate systems programming concepts while providing a functional shell environment with lexing, parsing, command execution, pipelines, redirections, environment expansion, builtins, and heredocs.

## Features

- **Complete Shell Pipeline**: Input String → Lexer → Parser → Simple Commands → Executor
- **Advanced I/O**: Input/Output redirection and pipelines
- **Environment Management**: Variable expansion and manipulation
- **Built-in Commands**: Essential shell builtins implementation
- **Heredoc Support**: Multi-line input processing
- **Error Handling**: Comprehensive error reporting
- **Memory Safe**: Proper memory management and cleanup

## Implementation Details

### The Lexer
The lexer tokenizes input strings into meaningful tokens using a linked list structure (`t_lexer`). It processes the input character by character, identifying operators, words, and special characters.

**Key Components:**
- `token_reader()`: Main tokenization function that processes the input string
- `handle_token()`: Identifies and processes operators (`|`, `>`, `<`, `>>`, `<<`)
- `read_words()`: Extracts command words and arguments
- `handle_quotes()`: Manages single and double quote processing
- Token types: `PIPE`, `GREAT`, `GREAT_GREAT`, `LESS`, `LESS_LESS`

**Structure:**
```c
typedef struct s_lexer {
    char *str;              // Token string
    t_tokens token;         // Token type
    int i;                  // Token index
    struct s_lexer *next;   // Next token
    struct s_lexer *prev;   // Previous token
} t_lexer;
```

###The Parser
The parser converts the token stream into executable command structures. Instead of building a traditional AST, it creates a flat command structure optimized for shell execution.

**Key Components:**
- `parser()`: Main parsing function that processes token lists
- `initialize_cmd()`: Creates command structures from tokens
- `handle_redirections()`: Processes redirection operators
- `count_pipes()`: Analyzes pipeline structure
- Error handling for syntax validation
  
**Structure:**
```c
typedef struct s_simple_cmds {
    char **str;                     // Command and arguments
    int (*builtin)(t_tools *, struct s_simple_cmds *); // Builtin function pointer
    int num_redirections;           // Redirection count
    char *hd_file_name;            // Heredoc filename
    t_lexer *redirections;         // Redirection list
    struct s_simple_cmds *next;    // Next command (for pipes)
    struct s_simple_cmds *prev;    // Previous command
} t_simple_cmds;
```

###Builtins
Built-in commands are implemented as function pointers stored in the command structure, allowing for direct execution without external process creation.

**Implemented Builtins:**
`mini_cd()`: Directory navigation with error handling
`mini_echo()`: Text output with flag support
`mini_env()`: Environment variable display
`mini_exit()`: Shell termination with exit codes
`mini_export()`: Environment variable creation/modification
`mini_pwd()`: Current directory display
`mini_unset()`: Environment variable removal
**Implementation: Each builtin is registered during command initialization and executed directly within the shell process, avoiding fork/exec overhead.**

###Executor
The executor manages command execution, handling both built-in commands and external programs through process creation and management.

**Key Components:**
-`executor()`: Main execution controller
-`handle_cmd()`: Manages individual command execution
-`check_redirections()`: Sets up I/O redirection
-Process management with `fork()` and `execve()`
-Pipeline handling with pipe creation and management
-Signal handling integration

**Execution Flow:**
1.Check for builtin commands
2.Set up redirections and pipes
3.Fork processes for external commands
4.Execute commands with proper environment
5.Wait for completion and handle exit codes

###Expander
The expander handles environment variable substitution and special parameter expansion within command arguments.

**Key Components:**
-`expander()`: Main expansion function
-Variable expansion ($VAR, ${VAR})
-Special parameter handling ($?, $0)
-Quote-aware expansion
-Integration with lexer for token processing

**Features:**
-Environment variable substitution
-Exit status expansion ($?)
-Proper handling within quoted strings
-Error handling for undefined variables

###Heredoc
Heredoc functionality allows multi-line input processing with delimiter-based termination, supporting variable expansion within the content.

**Implementation:**

-`heredoc()`: Main heredoc processor
-Temporary file creation in build directory
-Delimiter matching and termination
-Variable expansion within heredoc content
-Integration with redirection system
-Proper cleanup of temporary files

**Process:**
-Create temporary file with unique name
-Read input until delimiter is found
-Process variable expansion if required
-Set up input redirection to temporary file
-Clean up temporary files after execution

###Single Command
Single command execution handles individual commands with their arguments, redirections, and environment setup.

**Process:**
-Parse command and arguments
-Check for builtin commands
-Set up any redirections
-Execute command (builtin or external)
-Handle return values and cleanup

###Multiple Commands
Pipeline execution manages multiple commands connected through pipes, handling inter-process communication and data flow.

**Implementation:**
-Pipe creation between commands
-Process coordination with proper file descriptor management
-Sequential execution with data flow
-Error propagation through pipeline
-Proper cleanup of all processes

**Pipeline Process:**
1.Create pipes for each connection
2.Fork processes for each command
3.Set up file descriptors for data flow
4.Execute all commands concurrently
5.Wait for completion and collect exit codes

###Reset
The reset functionality ensures proper cleanup and state restoration between command executions and error conditions.

Components:
-`reset_tools()`: Clears shell state
-Memory cleanup for all data structures
-File descriptor closure
-Process cleanup and signal handling
-State restoration for error recovery

## Quick Start

### Prerequisites
- GCC compiler (C99 or later)
- Make
- Readline library (libreadline-dev on Ubuntu/Debian, readline on macOS via Homebrew)
- Unix-like operating system (Linux, macOS, Windows with WSL)

### Installation

```bash
# Clone the repository
git clone https://github.com/HemanthBangera/PicoShell.git

# Navigate to project directory
cd PicoShell

# Build the project
make

# Run the shell
./picoshell
```
