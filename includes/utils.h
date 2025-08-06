#ifndef UTILS_H
# define UTILS_H
# include "picoshell.h"

char **hb_arrdup(char **arr);
int implement_tools(t_tools *tools);
int	picoshell_loop(t_tools *tools);
int count_quotes(char* str);
int	find_matching_quote(char *line, int i, int *num_del, int del);

#endif