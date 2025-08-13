#include "error.h"

void parser_error(int error,t_tools *tools,t_lexer* lexer_list)
{
    hb_lexerclear(lexer_list);
    hb_error(error,tools);
}

int parser_double_token_error(t_tools *tools,t_lexer *lexer_list,t_tokens token)
{
    hb_putstr_fd("picoshell: syntax error near unexpected token ",
		STDERR_FILENO);
	if (token == GREAT)
		hb_putstr_fd("'>'\n", STDERR_FILENO);
	else if (token == GREAT_GREAT)
		hb_putstr_fd("'>>'\n", STDERR_FILENO);
	else if (token == LESS)
		hb_putstr_fd("'<'\n", STDERR_FILENO);
	else if (token == LESS_LESS)
		hb_putstr_fd("'<<'\n", STDERR_FILENO);
	else if (token == PIPE)
		hb_putstr_fd("'|'\n", STDERR_FILENO);
	else
		hb_putstr_fd("\n", STDERR_FILENO);  
      
    hb_lexerclear(&lexer_list);

    return(EXIT_FAILURE);
}
