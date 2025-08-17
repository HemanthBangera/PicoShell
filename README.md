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
