#include "picoshell.h"

int is_whitespace(char c)
{
    return (c==' ' || (c>8 && c<14));
}

int skip_spaces(char *str,int i)
{
    int j=0;
    while(is_whitespace(str[i+j]))
    {
        j++;
    }
    return j;
}

int add_node(char *str,t_tokens token,t_lexer **lexer_list)
{
    t_lexer *node;
    node = hb_lexernew(str,token);
    if(!node)
        return (0);
    hb_lexeradd_back(lexer_list,node);
    return (1);
}


int	read_words(char *str,int i, t_lexer **lexer_list)
{
	int	j;

	j = 0;
	while (str[i + j] && !(check_token(str[i + j])))
	{
		j += handle_quotes(i + j, str, 34);
		j += handle_quotes(i + j, str, 39);
		if (is_whitespace(str[i + j]))
			break ;
		else
			j++;
	}
	if (!add_node(hb_substr(str, i, j), 0, lexer_list))
		return (-1);
	return (j);
}


int token_reader(t_tools *tools)
{
    int i=0;
    int j;
    while(tools->args[i]){
        j=0;
        i += skip_spaces(tools->args,i);
        if(check_token(tools->args[i])){
            j = handle_token(tools->args,i,&tools->lexer_list);
        }
        else{
            j = read_words(tools->args,i,&tools->lexer_list);
        }
        if(j<0)
            return 0;
        i += j;
    }
    return 1;
}