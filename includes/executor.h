#ifndef EXECUTOR_H
# define EXECUTOR_H
# include "picoshell.h"
#include <fcntl.h>

t_simple_cmds	*call_expander(t_tools *tools, t_simple_cmds *cmd);
char *generate_heredoc_filename(void);
int create_heredoc(t_lexer *heredoc,bool quotes,t_tools *tools,char *file_name);
int hb_heredoc(t_tools *tools,t_lexer *heredoc,char *file_name);
int send_heredoc(t_tools *tools,t_simple_cmds *cmd);





#endif