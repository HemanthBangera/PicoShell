#ifndef UTILS_H
# define UTILS_H
# include "picoshell.h"

char **hb_arrdup(char **arr);
int implement_tools(t_tools *tools);
int	picoshell_loop(t_tools *tools);
int count_quotes(char* str);
int	find_matching_quotes(char *line, int i, int *num_del, int del);







t_lexer	*hb_lexernew(char *str, int token);
void hb_lexeradd_back(t_lexer **lst, t_lexer *new);
void hb_lexerclear(t_lexer **lst);
void	hb_lexerdelone(t_lexer **lst, int key);
void	hb_lexerdel_first(t_lexer **lst);
t_lexer	*hb_lexerclear_one(t_lexer **lst);




int handle_token(char *str,int i,t_lexer **lexer_list);
int check_token(char c);
int token_reader(t_tools *tools);
int add_node(char *str,t_tokens token,t_lexer **lexer_list);


#endif