#include "utils.h"

t_lexer	*hb_lexerclear_one(t_lexer **lst)
{
	if ((*lst)->str)
	{
		free((*lst)->str);
		(*lst)->str = NULL;
	}
	free(*lst);
	*lst = NULL;
	return (NULL);
}

void	hb_lexerdel_first(t_lexer **lst)
{
	t_lexer	*node;

	node = *lst;
	*lst = node->next;
	hb_lexerclear_one(&node);
	if (*lst)
		(*lst)->prev = NULL;
}


void	hb_lexerdelone(t_lexer **lst, int key)
{
	t_lexer	*node;
	t_lexer	*prev;
	t_lexer	*start;

	start = *lst;
	node = start;
	if ((*lst)->i == key)
	{
		hb_lexerdel_first(lst);
		return ;
	}
	while (node && node->i != key)
	{
		prev = node;
		node = node->next;
	}
	if (node)
		prev->next = node->next;
	else
		prev->next = NULL;
	if (prev->next)
		prev->next->prev = prev;
	hb_lexerclear_one(&node);
	*lst = start;
}

void hb_lexerclear(t_lexer **lst)
{
    t_lexer *tmp;

    if(!*lst)
        return;
    while(*lst)
    {
        tmp = (*lst)->next;
        if((*lst)->str)
            free((*lst)->str);
        free(*lst);
        *lst = tmp;
    }
    *lst = NULL;
}