#include "picoshell.h"

int	add_new_redirection(t_lexer *tmp, t_parser_tools *parser_tools)
{
	t_lexer	*node;
	int		index_1;
	int		index_2;

	node = hb_lexernew(hb_strdup(tmp->next->str), tmp->token);
	if (!node)
		parser_error(1, parser_tools->tools, parser_tools->lexer_list);
	hb_lexeradd_back(&parser_tools->redirections, node);
	index_1 = tmp->i;
	index_2 = tmp->next->i;
	hb_lexerdelone(&parser_tools->lexer_list, index_1);
	hb_lexerdelone(&parser_tools->lexer_list, index_2);
	parser_tools->num_redirections++;
	return (0);
}

void rm_redirections(t_parser_tools *parser_tools)
{
    t_lexer *tmp;

    tmp = parser_tools->lexer_list;
    while(tmp && tmp->token == 0)
    {
        tmp = tmp->next;
    }
    if(!tmp || tmp->token == PIPE)
    {
        return;
    }
    if(!tmp->next)
    {
        parser_error(0,parser_tools->tools,parser_tools->lexer_list);
    }
    if(tmp->next->token)
    {
        parser_double_token_error(parser_tools->tools,
			parser_tools->lexer_list, tmp->next->token);
    }
    if((tmp->token >= GREAT && tmp->token <= LESS_LESS))
    {
            add_new_redirection(tmp,parser_tools);
    }
    rm_redirections(parser_tools);
}