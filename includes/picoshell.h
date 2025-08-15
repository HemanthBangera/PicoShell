
#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# include "libhb.h"
# include "parser.h"
# include "utils.h"
# include "color.h"
# include "error.h"
# include "lexer.h"
# include "builtins.h"

int find_pwd(t_tools *tools);
int	parse_envp(t_tools *tools);
void sigint_handler(int sig);
void init_signals(void);
size_t dollar_sign(char* str);
int	after_dol_length(char *str, int j);
char *char_to_str(char c);
char *delete_quotes(char *str, char c);
char **expander(t_tools *tools, char **str);
char *expander_str(t_tools *tools, char *str);char *detect_dollar_sign(t_tools *tools,char *str);
int	handle_digit_after_dollar(int j, char *str);
int loop_if_dollar_sign(t_tools *tools,char *str,char **tmp,int j);
int	question_mark(char **tmp);



typedef struct s_global
{
	int	error_num;
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
}	t_global;

t_global g_global;


#endif