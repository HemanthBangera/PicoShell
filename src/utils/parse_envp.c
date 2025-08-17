#include "picoshell.h"

int find_pwd(t_tools *tools){
    int i=0;

    while(tools->envp[i]){
        if(!hb_strncmp(tools->envp[i],"PWD=",4)){
            tools->pwd = hb_substr(tools->envp[i],4
                ,hb_strlen(tools->envp[i])-4);
        }
        if(!hb_strncmp(tools->envp[i],"OLDPWD=",7)){
            tools->old_pwd = hb_substr(tools->envp[i],7
                ,hb_strlen(tools->envp[i])-7);
        }
        i++;
    }
    return (1);
}

char *find_path(char **envp){
    int i=0;
    while(envp[i])
    {
        if(!hb_strncmp(envp[i],"PATH=",5)){
            return (hb_substr(envp[i],5,hb_strlen(envp[i])-5));
        }
        i++;
    }
    return (hb_strdup("\0"));
}

int parse_envp(t_tools *tools){
    char *path_from_envp;
    int i=0;
    char *tmp;

    path_from_envp = find_path(tools->envp);
    tools->paths = hb_split(path_from_envp,':');
    free(path_from_envp);
    
    if (!tools->paths) {
        return (EXIT_FAILURE);
    }

    while(tools->paths[i]){
        if(hb_strncmp(&tools->paths[i][hb_strlen(tools->paths[i])-1],"/",1) != 0)
        {
            tmp = hb_strjoin(tools->paths[i],"/");
            free(tools->paths[i]);
            tools->paths[i] = tmp;
        }
        i++;
    }
    return (EXIT_SUCCESS);
}