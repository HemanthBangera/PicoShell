#include "builtins.h"

void	print_lines(int i, char **str, int out)
{
	while (str[i])
	{
		hb_putstr_fd(str[i++], out);
		if (str[i])
			hb_putchar_fd(' ', out);
	}
}

int mini_echo(t_tools *tools,t_simple_cmds *simple_cmd)
{
    int i=1;
    int j;
    bool n_option=false;

    (void) tools;
    while(simple_cmd->str[i] && simple_cmd->str[i][0] == '-'
        && simple_cmd->str[i][i] == 'n')
    {
        j =1;
        while(simple_cmd->str[i][j] == 'n')
            j++;
        if(simple_cmd->str[i][j] == '\0')
            n_option = true;
        else
            break;
        i++;
    }
    print_lines(i,simple_cmd->str,STDOUT_FILENO);
    if(n_option == false)
        hb_putchar_fd('\n',STDOUT_FILENO);
    return EXIT_SUCCESS;
}