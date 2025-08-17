#include "builtins.h"

char	*find_path_ret(char *str, t_tools *tools)
{
	int	i;

	i = 0;
	while (tools->envp[i])
	{
		if (!hb_strncmp(tools->envp[i], str, hb_strlen(str)))
			return (hb_substr(tools->envp[i], hb_strlen(str),
					hb_strlen(tools->envp[i]) - hb_strlen(str)));
		i++;
	}
	return (NULL);
}


int specific_path(t_tools *tools,char *str)
{
    char *tmp;
    int ret;

    tmp = find_path_ret(str,tools);
	if (!tmp)
    {
        hb_putstr_fd("picoshell: ", STDERR_FILENO);
        hb_putstr_fd(str, STDERR_FILENO);
        hb_putendl_fd(": not set", STDERR_FILENO);
        return -1;
    }
    ret = chdir(tmp);
	
    if(ret!=0)
    {
        str = hb_substr(str,0,hb_strlen(str)-1);
        hb_putstr_fd(str,STDERR_FILENO);
        free(str);
        hb_putendl_fd("not set",STDERR_FILENO);
    }
	free(tmp);
    return ret;
}

void	add_path_to_env(t_tools *tools)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tools->envp[i])
	{
		if (!hb_strncmp(tools->envp[i], "PWD=", 4))
		{
			tmp = hb_strjoin("PWD=", tools->pwd);
			if (tmp)
            {
                free(tools->envp[i]);
                tools->envp[i] = tmp;
            }
		}
		else if (!hb_strncmp(tools->envp[i], "OLDPWD=", 7) && tools->old_pwd)
		{
			tmp = hb_strjoin("OLDPWD=", tools->old_pwd);
			if (tmp)
            {
                free(tools->envp[i]);
                tools->envp[i] = tmp;
            }
		}
		i++;
	}
}



int mini_cd(t_tools *tools,t_simple_cmds *simple_cmd)
{
    int ret;

    if(!simple_cmd->str[1])
        ret = specific_path(tools,"HOME=");
    else if(hb_strncmp(simple_cmd->str[1],"-",1)==0)
        ret = specific_path(tools,"OLDPWD=");
    else
    {
        ret = chdir(simple_cmd->str[1]);
        if (ret != 0)
		{
			hb_putstr_fd("picoshell: ", STDERR_FILENO);
			hb_putstr_fd(simple_cmd->str[1], STDERR_FILENO);
			perror(" ");
		}
    }
    if(ret != 0)
        return EXIT_FAILURE;

    change_path(tools);
    add_path_to_env(tools);
    return EXIT_SUCCESS;
    
    
}