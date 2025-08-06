
#ifndef LIBHB_H
# define LIBHB_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

void *hb_bzero(void* str,size_t n);
char *ft_strdup(const char *s1);
void *hb_calloc(size_t size,size_t total);
size_t hb_strlen(char* str);
int hb_strncmp(const char *s1, const char *s2, size_t n);
char *hb_substr(char const *s, unsigned int start, size_t len);
char **hb_split(char const *s, char c);
void free_arr(char **arr);
void hb_putchar_fd(char c, int fd);
void hb_putstr_fd(char *s, int fd);
char *hb_strtrim(char const *s1, char const *set);
void hb_putendl_fd(char *s,int i);


#endif