#include "picoshell.h"

void count_pipes(t_lexer *lexer_list,t_tools *tools)
{
    t_lexer *tmp;
    tmp = lexer_list;
    tools->pipes = 0;

    while(tmp)
    {
        if(tmp->token == PIPE)
        {
            tools->pipes++;
        }
        tmp = tmp->next;
    }
}