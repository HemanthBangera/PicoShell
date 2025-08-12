#include "libhb.h"

void	hb_putnbr_fd(int n, int fd)
{
	long long	j;

	j = (long long)n;
	if (j < 0)
	{
		hb_putchar_fd('-', fd);
		j *= -1;
	}
	if (j < 10)
		hb_putchar_fd(j + '0', fd);
	if (j >= 10)
	{
		hb_putnbr_fd(j / 10, fd);
		hb_putchar_fd((j % 10) + '0', fd);
	}
}
