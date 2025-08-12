#include "libhb.h"

int	count_c(char const *s, char c)
{
	size_t	i;
	int		c_count;

	i = 0;
	c_count = 0;
	while (i < hb_strlen(s))
	{
		if (s[i] != c)
			c_count++;
		while (s[i] != c && i < hb_strlen(s))
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

int	strlen_c(char const *s, char c, int s_i)
{
	int	i;

	i = 0;
	while (s[s_i] != c && s[s_i] != '\0')
	{
		s_i++;
		i++;
	}
	return (i);
}

char	**create_arr(char const *s, char c, int c_count, char **split_arr)
{
	int	s_i;
	int	s_a_i;
	int	num_of_char;

	s_i = 0;
	s_a_i = 0;
	num_of_char = 0;
	while (s_a_i < c_count)
	{
		while (s[s_i] == c)
			s_i++;
		num_of_char = strlen_c(s, c, s_i);
		split_arr[s_a_i] = (char *)hb_calloc(num_of_char + 1, sizeof(char));
		if (!split_arr)
			return (NULL);
		hb_strlcpy(split_arr[s_a_i], &s[s_i], num_of_char + 1);
		s_i += num_of_char;
		s_a_i++;
	}
	return (split_arr);
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
