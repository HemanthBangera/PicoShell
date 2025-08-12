#include "libhb.h"

char	*hb_strjoin(const char *s1,const char *s2)
{
	int		len;
	char	*s1_2;
	int		i;

	if ((!s1 || !s2) || (!s1 && !s2))
		return (0);
	len = hb_strlen(s1) + hb_strlen(s2);
	s1_2 = (char *)malloc(len * sizeof(char) + 1);
	i = 0;
	if (!s1_2)
		return (0);
	while (*s1)
	{
		s1_2[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		s1_2[i] = *s2;
		s2++;
		i++;
	}
	s1_2[i] = '\0';
	return (s1_2);
}
