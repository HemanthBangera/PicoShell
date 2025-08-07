#include "picoshell.h"

int minishell_loop(t_tools *tools);

int implement_tools(t_tools *tools)
{
    tools->simple_cmds = NULL;
    tools->lexer_list = NULL;
    tools->heredoc = false;
    tools->pid = NULL;
    tools->reset = false;
    g_global.stop_heredoc = 0;
    g_global.in_cmd = 0;
    g_global.in_heredoc = 0;
    parse_envp(tools);
    init_signals();
    return (1);
}




int picoshell_loop(t_tools *tools){
    char *tmp;

    tools->args = readline(READLINE_MSG);
    tmp = hb_strtrim(tools->args," ");
    free(tools->args);
    tools->args = tmp;
    if(!tools->args){
        hb_putendl_fd("exit",STDERR_FILENO);
        exit(EXIT_SUCCESS);
    }
    if(tools->args[0]=='\0'){
        return (reset_tools(tools));
    }
    add_history(tools->args);
    
    if(!count_quotes(tools->args)){
        return (hb_error(2,tools));
    }
    if(!token_reader(tools))
        return (hb_error(1,tools));
    

}