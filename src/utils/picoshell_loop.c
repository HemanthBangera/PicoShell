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
