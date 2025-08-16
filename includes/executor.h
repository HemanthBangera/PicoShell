#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "picoshell.h"
#include <fcntl.h>

t_simple_cmds	*call_expander(t_tools *tools, t_simple_cmds *cmd);
char *generate_heredoc_filename(void);
int create_heredoc(t_lexer *heredoc,bool quotes,t_tools *tools,char *file_name);
int hb_heredoc(t_tools *tools,t_lexer *heredoc,char *file_name);
int send_heredoc(t_tools *tools,t_simple_cmds *cmd);
char *join_split_str(char **split_str, char *new_str);
char **resplit_str(char **double_arr);
int	check_append_outfile(t_lexer *redirections);
int	handle_infile(char *file);
int	handle_outfile(t_lexer *redirection);
int	check_redirections(t_simple_cmds *cmd);
int find_cmd(t_simple_cmds *cmd,t_tools *tools);
void handle_cmd(t_simple_cmds *cmd,t_tools *tools);
void single_cmd(t_simple_cmds *cmd,t_tools *tools);
void dup_cmd(t_simple_cmds *cmd, t_tools *tools, int end[2], int fd_in);


#endif