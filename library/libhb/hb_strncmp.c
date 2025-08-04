#include "picoshell.h"
#include "libhb.h"

int hb_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i = 0;

    while (i < n)
    {
        if ((unsigned char)s1[i] != (unsigned char)s2[i])
            return ((unsigned char)s1[i] - (unsigned char)s2[i]);
        if (s1[i] == '\0' || s2[i] == '\0')
            break;
        i++;
    }
    return 0;
}
