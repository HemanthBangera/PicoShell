# ============================================================================
# PICOSHELL PROJECT MAKEFILE
# ============================================================================
# This Makefile builds a custom shell implementation called PicoShell
# It handles compilation of multiple source files, library linking, and testing

# ============================================================================
# PROJECT CONFIGURATION
# ============================================================================

# NAME: The final executable name that will be created
NAME = picoshell

# CC: The compiler to use (gcc is the GNU C Compiler)
CC = gcc

# CFLAGS: Compilation flags that control how the code is compiled
# -Wall: Enable all common warnings
# -Wextra: Enable extra warnings beyond -Wall
# -Werror: Treat all warnings as errors (forces clean code)
# -g: Include debugging information in the executable
CFLAGS = -Wall -Wextra -Werror -g

# READLINE_DIR: Find the readline library directory
# $(shell ...): Execute a shell command and use its output
# brew --prefix readline: Get readline path on macOS (if brew is installed)
# 2>/dev/null: Suppress error messages if brew doesn't exist
# || echo "/usr": If brew fails, use /usr as default (Linux systems)
READLINE_DIR = $(shell brew --prefix readline 2>/dev/null || echo "/usr")

# ============================================================================
# DIRECTORY STRUCTURE
# ============================================================================

# SRCDIR: Directory containing all source code files
SRCDIR = src

# LIBDIR: Directory containing our custom library (libhb)
LIBDIR = library/libhb

# INCDIR: Directory containing all header files (.h files)
INCDIR = includes

# OBJDIR: Directory where compiled object files (.o) will be stored
# This keeps the project organized by separating source and compiled files
OBJDIR = obj

# ============================================================================
# COMPILER INCLUDE PATHS
# ============================================================================

# INCLUDES: Tell the compiler where to look for header files
# -I: Include directory flag
# Each -I adds a directory to the compiler's search path for #include statements
INCLUDES = -I$(INCDIR) -I$(LIBDIR) -I$(READLINE_DIR)/include

# ============================================================================
# LIBRARY LINKING CONFIGURATION
# ============================================================================

# LIBS: Libraries to link against
# -lreadline: Link with readline library (for command line editing)
# -lhistory: Link with history library (for command history feature)
LIBS = -lreadline -lhistory

# LDFLAGS: Linker flags specifying where to find libraries
# -L: Library directory flag (tells linker where to look for .so/.a files)
LDFLAGS = -L$(READLINE_DIR)/lib

# ============================================================================
# SOURCE FILE COLLECTION
# ============================================================================

# LIBHB_SRCS: Collect all .c files from our custom library directory
# $(wildcard pattern): Find all files matching the pattern
# This automatically includes all .c files in library/libhb/
LIBHB_SRCS = $(wildcard $(LIBDIR)/*.c)

# MAIN_SRCS: Explicitly list main source files and use wildcard for subdirectories
# This includes:
# - main.c (program entry point)
# - signals.c (signal handling)
# - All .c files in error/ subdirectory
# - All .c files in lexer/ subdirectory
# - All .c files in utils/ subdirectory
# - All .c files in builtins/ subdirectory
# - All .c files in executor/ subdirectory
# - All .c files in expander/ subdirectory
# - All .c files in parser/ subdirectory
MAIN_SRCS = $(SRCDIR)/main.c \
           $(SRCDIR)/signals.c \
           $(wildcard $(SRCDIR)/error/*.c) \
           $(wildcard $(SRCDIR)/lexer/*.c) \
           $(wildcard $(SRCDIR)/utils/*.c) \
           $(wildcard $(SRCDIR)/builtins/*.c) \
           $(wildcard $(SRCDIR)/executor/*.c) \
           $(wildcard $(SRCDIR)/expander/*.c) \
           $(wildcard $(SRCDIR)/parser/*.c)

# ============================================================================
# OBJECT FILE MAPPING
# ============================================================================

# LIBHB_OBJS: Convert library source files to object file paths
# $(var:pattern=replacement): Substitution reference
# Changes library/libhb/file.c to obj/libhb/file.o
LIBHB_OBJS = $(LIBHB_SRCS:$(LIBDIR)/%.c=$(OBJDIR)/libhb/%.o)

# MAIN_OBJS: Convert main source files to object file paths
# Changes src/path/file.c to obj/path/file.o
MAIN_OBJS = $(MAIN_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# ALL_OBJS: Combine all object files into one variable
# This will be used to link the final executable
ALL_OBJS = $(LIBHB_OBJS) $(MAIN_OBJS)

# ============================================================================
# TEST CONFIGURATION
# ============================================================================

# TEST_SRCS: Source files specifically for testing
TEST_SRCS = $(SRCDIR)/test.c

# TEST_OBJS: Convert test source files to object files
TEST_OBJS = $(TEST_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# TEST_NAME: Name of the test executable
TEST_NAME = test_picoshell

# ============================================================================
# PHONY TARGETS DECLARATION
# ============================================================================

# .PHONY: Tells make that these targets don't create files with these names
# This prevents conflicts if files with these names exist in the directory
.PHONY: all clean fclean re test help run debug check

# ============================================================================
# BUILD RULES
# ============================================================================

# DEFAULT TARGET: 'all' is the default target (runs when you type just 'make')
all: $(NAME)

# MAIN EXECUTABLE RULE: How to build the main program
# $(NAME): The target depends on all object files
# @echo: The @ suppresses echoing the command itself
# The actual linking command combines all object files with libraries
$(NAME): $(ALL_OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(ALL_OBJS) $(LDFLAGS) $(LIBS) -o $(NAME)
	@echo "✓ $(NAME) compiled successfully!"

# ============================================================================
# OBJECT FILE COMPILATION RULES
# ============================================================================

# PATTERN RULE: How to compile main source files to object files
# $(OBJDIR)/%.o: Target pattern (any .o file in obj directory)
# $(SRCDIR)/%.c: Prerequisite pattern (corresponding .c file in src)
# mkdir -p $(dir $@): Create directory structure if it doesn't exist
# $<: The first prerequisite (the .c file)
# $@: The target (the .o file)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# PATTERN RULE: How to compile library files to object files
# Similar to above but for files in the library directory
$(OBJDIR)/libhb/%.o: $(LIBDIR)/%.c
	@mkdir -p $(dir $@)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ============================================================================
# TEST BUILD RULES
# ============================================================================

# TEST TARGET: Build the test executable
test: $(TEST_NAME)

# TEST EXECUTABLE RULE: Link test files with library objects
# Tests only need the library objects, not the main program objects
$(TEST_NAME): $(TEST_OBJS) $(LIBHB_OBJS)
	@echo "Building test executable..."
	@$(CC) $(CFLAGS) $(TEST_OBJS) $(LIBHB_OBJS) -o $(TEST_NAME)
	@echo "✓ Test executable compiled successfully!"
	@echo "Run with: ./$(TEST_NAME)"

# ============================================================================
# CLEANUP RULES
# ============================================================================

# CLEAN: Remove compiled object files but keep executables
# This forces recompilation of all source files on next build
clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJDIR)

# FCLEAN: Remove everything generated by the build process
# 'fclean' depends on 'clean', so it runs clean first, then removes executables
fclean: clean
	@echo "Cleaning executables..."
	@rm -f $(NAME) $(TEST_NAME)

# RE: Complete rebuild (clean everything and build again)
# This ensures a fresh build from scratch
re: fclean all

# ============================================================================
# DEVELOPMENT HELPER TARGETS
# ============================================================================

# RUN: Build and immediately run the program
# This is convenient for quick testing during development
run: $(NAME)
	@echo "Starting $(NAME)..."
	@./$(NAME)

# DEBUG: Build with additional debug flags
# CFLAGS += -DDEBUG: Add -DDEBUG to compilation flags for this target only
# This can enable debug-specific code using #ifdef DEBUG
debug: CFLAGS += -DDEBUG
debug: $(NAME)

# CHECK: Syntax check without building executables
# -fsyntax-only: Only check syntax, don't generate object files
# This is fast and catches syntax errors without full compilation
check:
	@echo "Checking syntax..."
	@$(CC) $(CFLAGS) $(INCLUDES) -fsyntax-only $(MAIN_SRCS) $(LIBHB_SRCS)
	@echo "✓ Syntax check passed!"

# ============================================================================
# HELP TARGET
# ============================================================================

# HELP: Display available make targets and their descriptions
# This is useful for new developers or when you forget available commands
help:
	@echo "Available targets:"
	@echo "  all     - Build the main executable"
	@echo "  test    - Build the test executable"
	@echo "  run     - Build and run the shell"
	@echo "  debug   - Build with debug flags"
	@echo "  check   - Check syntax without building"
	@echo "  clean   - Remove object files"
	@echo "  fclean  - Remove all generated files"
	@echo "  re      - Clean and rebuild"
	@echo "  help    - Show this help message"
