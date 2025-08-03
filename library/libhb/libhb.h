
#ifndef LIBHB_H
# define LIBHB_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

void *hb_bzero(void* str,size_t n);
char *ft_strdup(const char *s1);
void *hb_calloc(size_t size,size_t total);
size_t hb_strlen(char* str);

#endif