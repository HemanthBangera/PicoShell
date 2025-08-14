#include "picoshell.h"

size_t dollar_sign(char* str)
{
    size_t i;
    i=0;
    while(str[i])
    {
        if(str[i]=='$')
            return (i+1);
        i++;
    }
    return (0);
}

int	after_dol_length(char *str, int j)
{
	int	i;

	i = j + 1;
	while (str[i] != '\0' && str[i] != '$' && str[i] != ' '
		&& str[i] != '\"' && str[i] != '\'' && str[i] != '=' && str[i] != '-'
		&& str[i] != ':')
		i++;
	return (i);
}

char	*char_to_str(char c)
{
	char	*str;

	str = hb_calloc(sizeof(char), 2);
	str[0] = c;
	return (str);
}

char	*delete_quotes(char *str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			j = 0;
			while (str[i + j] == c)
				j++;
			hb_strlcpy(&str[i], &str[i + j], strlen(str) - i);
		}
		i++;
	}
	return (str);
}

int	question_mark(char **tmp)
{
	free(*tmp);
	*tmp = ft_itoa(g_global.error_num);
	return (ft_strlen(*tmp) + 1);
}
