#include "libhb.h"

char	*hb_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;
	size_t			strln;

	strln = hb_strlen(s);
	if (!s)
		return (0);
	if (start > strln)
		return (hb_strdup(""));
	if (len > strln - start)
		return (hb_strdup(s + start));
	i = 0;
	substr = (char *)malloc((len * sizeof(char)) + 1);
	if (!substr)
		return (0);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
