#include "picoshell.h"

char **hb_arrdup(char **arr)
{
	char	**rtn;
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	rtn = hb_calloc(sizeof(char *), i + 1);
	if (!rtn)
		return (NULL);
	i = 0;
	while (arr[i] != NULL)
	{
		rtn[i] = hb_strdup(arr[i]);
		if (rtn[i] == NULL)
		{
			free_arr(rtn);
			return (rtn);
		}
		i++;
	}
	return (rtn);
}

int	find_matching_quote(char *line, int i, int *num_del, int del)
{
	int	j;

	j = i + 1;
	*num_del += 1;
	while (line[j] && line[j] != del)
		j++;
	if (line[j] == del)
		*num_del += 1;
	return (j - i);
}

int count_quotes(char* str)
{
	int i = 0;
	int s =0;
	int d = 0;

	while(str[i]){
		if(str[i] == 34)
			i += find_matching_quotes(str,i,&d,34);
		if(str[i] == 35)
			i += find_matching_quotes(str,i,&s,35);
	}
	if((d>0 && d%2!=0) || ( s>0 && s%2!=0)){
		return (0);
	}
	return (1);
}