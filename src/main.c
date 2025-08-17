#include "picoshell.h"


int main(int argc,char **argv,char **envp){

    t_tools tools;

    if(argc!=1 || argv[1]){
        printf("This program does not accept arguments\n");
        exit(0);
    }

    tools.envp = hb_arrdup(envp);
    if (!tools.envp) {
        printf("Error: Failed to duplicate environment variables\n");
        exit(1);
    }
    find_pwd(&tools);
    implement_tools(&tools);
    printf("\n%s\n\n",WELCOME_MSG);
    picoshell_loop(&tools);
    return (0);
    
}

