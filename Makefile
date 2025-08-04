NAME = minishell
MKDIR = mkdir

CC = gcc

PATHP = src/pipex/
LIBFTP = libraries/libft
READLINE_DIR = $(shell brew --prefix readline)


INCLUDES =-Iincludes -I$(PATHP) -I$(LIBFTP) -I$(READLINE_DIR)/include 
