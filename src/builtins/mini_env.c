#include "builtins.h"

int mini_env(t_tools *tools,t_simple_cmds *simple_cmd)
{
    int i;
    (void) simple_cmd;
    i=0;
    while(tools->envp[i])
    {
        hb_putendl_fd(tools->envp[i],STDOUT_FILENO);
        i++;
    }
    return EXIT_SUCCESS;
}