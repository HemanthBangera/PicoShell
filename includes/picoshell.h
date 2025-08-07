
#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <unistd.h>

# include "libhb.h"
# include "parser.h"
# include "utils.h"
# include "color.h"
# include "error.h"
# include "lexer.h"

int find_pwd(t_tools *tools);
int	parse_envp(t_tools *tools);
void sigint_handler(int sig);
void init_signals(void);

typedef struct s_global
{
	int	error_num;
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
}	t_global;

t_global g_global;


#endif