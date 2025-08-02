#ifndef PARSER_H
# define PARSER_H
# include "picoshell.h"


typedef struct s_tools
{
    char *args;
    char **paths;
    char **enpv;
} t_tools;



int find_pwd(t_tools *tools);

#endif