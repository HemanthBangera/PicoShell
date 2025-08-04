#include "libhb.h"

int	count_c(char const *s, char c)
{
	size_t	i;
	int		c_count;

	i = 0;
	c_count = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
			c_count++;
		while (s[i] != c && i < ft_strlen(s))
			i++;
		i++;
	}
	return (c_count);
}


void free_arr(char **arr){
    size_t i=0;

    while(arr[i]){
        free(arr[i]);
        i++;
    }

    free(arr);
}

char **hb_split(char const *s, char c)
{
	int		c_count;
	char	**split_arr;

	if (!s)
		return (NULL);
	c_count = count_c(s, c);
	split_arr = hb_calloc(c_count + 1, sizeof(char *));
	if (!split_arr)
		return (NULL);
	if (!s || c_count == 0)
		return (split_arr);
	if (!create_arr(s, c, c_count, split_arr))
	{
		free_arr(split_arr);
		return (NULL);
	}
	return (split_arr);
}
