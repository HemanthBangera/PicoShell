#include "libhb.h"

void hb_putendl_fd(char *s, int fd)
{
    if (!s)
        return;
    hb_putstr_fd(s, fd);
    hb_putchar_fd('\n', fd);
}