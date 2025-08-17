#include "builtins.h"

int mini_pwd(t_tools *tools, t_simple_cmds *simple_cmd)
{
    char *current_dir;
    char buffer[4096];  
    
    (void) simple_cmd;
    
    if (getcwd(buffer, sizeof(buffer)) == NULL) {
        hb_putendl_fd("pwd: getcwd failed", STDERR_FILENO);
        return EXIT_FAILURE;
    }
    
    
    current_dir = hb_strdup(buffer);
    if (!current_dir) {
        hb_putendl_fd("pwd: memory allocation failed", STDERR_FILENO);
        return EXIT_FAILURE;
    }
    
    
	tools->pwd = current_dir;
	hb_putendl_fd(tools->pwd,STDOUT_FILENO);
    
    free(current_dir);
    return EXIT_SUCCESS;
}