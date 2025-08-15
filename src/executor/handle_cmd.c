#include "executor.h"

void single_cmd(t_simple_cmds *cmd,t_tools *tools)
{
    int pid;
    int status;

    tools->simple_cmds = call_expander(tools,tools->simple_cmds);
    if (cmd->builtin == mini_cd || cmd->builtin == mini_exit
		|| cmd->builtin == mini_export || cmd->builtin == mini_unset)
	{
		g_global.error_num = cmd->builtin(tools, cmd);
		return ;
	}
	send_heredoc(tools, cmd);
}