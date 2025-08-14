#include "executor.h"

t_simple_cmds	*call_expander(t_tools *tools, t_simple_cmds *cmd)
{
	t_lexer	*start;

	cmd->str = expander(tools, cmd->str);
	start = cmd->redirections;
	while (cmd->redirections)
	{
		if (cmd->redirections->token != LESS_LESS)
			cmd->redirections->str
				= expander_str(tools, cmd->redirections->str);
		cmd->redirections = cmd->redirections->next;
	}
	cmd->redirections = start;
	return (cmd);
}