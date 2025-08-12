#include "picoshell.h"



int parser(t_tools *tools)
{
    t_simple_cmds *node;
    t_parser_tools parser_tools;

    tools->simple_cmds = NULL;
    count_pipes(tools->lexer_list,tools);
    if(tools->lexer_list->token == PIPE){
        return (parser_double_token_error(tools,tools->lexer_list,tools->lexer_list->token));
    }
    
}