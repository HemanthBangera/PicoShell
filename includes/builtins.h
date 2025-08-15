#ifndef BUILTINS_H
# define BUILTINS_H
# include <dirent.h>
# include "picoshell.h"

size_t equal_sign(char *str);
int	mini_pwd(t_tools *tools, t_simple_cmds *simple_cmd);
char *find_path_ret(char *str, t_tools *tools);
int specific_path(t_tools *tools,char *str);
void add_path_to_env(t_tools *tools);
int mini_cd(t_tools *tools,t_simple_cmds *simple_cmd);
void print_lines(int i, char **str, int out);
int mini_echo(t_tools *tools,t_simple_cmds *simple_cmd);
int mini_env(t_tools *tools,t_simple_cmds *simple_cmd);
int	check_valid_identifier(char c);
int check_parameter(char *str);
char **whileloop_add_var(char **arr, char **rtn, char *str);
char **whileloop_add_var(char **arr, char **rtn, char *str);
char **add_var(char **arr, char *str);
int mini_export(t_tools *tools,t_simple_cmds *simple_cmd);
char **whileloop_del_var(char **arr, char **rtn, char *str);
char **del_var(char **arr, char *str);
int	unset_error(t_simple_cmds *simple_cmd);
int	mini_unset(t_tools *tools, t_simple_cmds *simple_cmd);
void free_tools(t_tools *tools);
int is_str_digit(char *str);
void determine_exit_code(char **str);
int mini_exit(t_tools *tools, t_simple_cmds *simple_cmd);
int (*builtin_arr(char *str))(t_tools *tools, t_simple_cmds *simple_cmd);
void change_path(t_tools *tools);

#endif