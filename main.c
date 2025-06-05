/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: giomastr <giomastr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:10:42 by giomastr          #+#    #+#             */
/*   Updated: 2025/06/05 14:31:28 by giomastr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	initmini(t_mini *mini)
{
	mini->cmd = NULL;
	mini->exit_code = 0;
}

int	main(int argc, char **argv, char *envp[])
{
	t_mini	mini;

	(void)argc;
	(void)argv;
	initenv(&mini, envp);  // mod
	initmini(&mini);
	signal(SIGINT, sig_handler);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		mini.cmd = readline("$> ");
		mini.exit_code = getsignal(&mini);
		if (mini.cmd == NULL)
		{
			ft_putstr_fd("exit\n", 1);
			ft_clean(&mini);
			exit(0); //check exit-code
		}
		add_history(mini.cmd);
		mini.cmd = ft_strtrim(mini.cmd, " ");
		/*if (mini.cmd[0] != '\0' && parsing(mini.cmd) == 0)
		{

			t_cmd *cmd_list = parse_command_line(cmd);
			if (cmd_list)
			{
				mini.exit_code = execute_pipeline(cmd_list, &mini);
				free_cmd_list(cmd_list);
			}
		*/
/* 			mini.mtx_cmd = ft_split(mini.cmd, ' ');
			mini.exit_code = excute_cmd(mini.mtx_cmd, &mini);
			free(mini.cmd);
			free_mtx(mini.mtx_cmd);
			while (wait(NULL) > 0)
				;
		}*/
		//env(&mini);
		char **mat = ft_split(mini.cmd, ' ');
		export_command(&mini, mat);
		free(mini.cmd);
		free_mtx(mat);
	}
	return (0);
}