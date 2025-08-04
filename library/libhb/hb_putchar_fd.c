#include "libhb.h"

void	hb_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
