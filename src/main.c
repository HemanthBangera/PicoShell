#include "picoshell.h"


int main(int argc,char **argv,char **envp){

    t_tools tools;

    if(argc!=1 || argv[1]){
        printf("This program does not accept arguments\n");
        exit(0);
    }

    tools.envp = hb_arrdup(envp);
    find_pwd(&tools);
    
}

