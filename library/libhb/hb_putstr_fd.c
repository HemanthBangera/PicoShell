#include "libhb.h"

void	hb_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		hb_putchar_fd(s[i], fd);
		i++;
	}
}
