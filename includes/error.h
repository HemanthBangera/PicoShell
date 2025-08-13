#ifndef ERROR_H
# define ERROR_H
# include "picoshell.h"

int	hb_error(int error, t_tools *tools);
int parser_double_token_error(t_tools *tools,t_lexer *lexer_list,t_tokens token);
void parser_error(int error,t_tools *tools,t_lexer* lexer_list);


#endif