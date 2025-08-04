#include "libhb.h"

char *ft_strdup(const char *s1)
{
	char	*s2;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1);
	s2 = (char *)malloc((size * sizeof(char)) + 1);
	if (!s2)
		return (0);
	while (i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
