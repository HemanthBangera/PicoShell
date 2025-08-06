#include "picoshell.h"

int	hb_error(int error, t_tools *tools)
{
	hb_putstr_fd("minishell: ", STDERR_FILENO);
	if (error == 0)
		hb_putstr_fd("syntax error near unexpected token 'newline'\n",
			STDERR_FILENO);
	else if (error == 1)
		hb_putstr_fd("memory error: unable to assign memory\n", STDERR_FILENO);
	else if (error == 2)
		hb_putstr_fd("syntax error: unable to locate closing quotation\n",
			STDERR_FILENO);
	else if (error == 3)
		hb_putstr_fd("Parser problem\n", STDERR_FILENO);
	else if (error == 4)
		hb_putstr_fd("Failed to create pipe\n", STDERR_FILENO);
	else if (error == 5)
		hb_putstr_fd("Failed to fork\n", STDERR_FILENO);
	else if (error == 6)
		hb_putstr_fd("outfile: Error\n", STDERR_FILENO);
	else if (error == 7)
		hb_putstr_fd("infile: No such file or directory\n", STDERR_FILENO);
	else if (error == 8)
		hb_putendl_fd("Path does not exist", STDERR_FILENO);
	reset_tools(tools);
	return (EXIT_FAILURE);
}