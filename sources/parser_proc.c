/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:58:58 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/04 19:08:34 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

size_t				count_child(t_cmd *cmd)
{
	size_t			childs;

	childs = 0;
	while (cmd != NULL)
	{
		if (cmd->bin_type == BIN || ft_strcmp(cmd->bin, "env") == 0
		|| ft_strcmp(cmd->bin, "echo") == 0 || cmd->redir != NULL)
			++childs;
		cmd = cmd->next;
	}
	return (childs);
}

static int			kill_child(int forks, pid_t *child_tab)
{
	int				i;

	i = 0;
	while (i < forks)
	{
		if (child_tab[i] != 0)
			if (kill(child_tab[i], SIGKILL) == -1)
				return (-1);
		++i;
	}
	return (0);
}

int					wait_child(pid_t *child_tab, int forks)
{
	siginfo_t		infos;
	int				i;
	int				last_ret;

	while (42)
	{
		i = 0;
		if (waitid(P_ALL, 0, &infos, WEXITED) == -1)
			break ;
		while (i < forks)
		{
			if (child_tab[i] == infos.si_pid)
			{
				child_tab[i] = 0;
				last_ret = infos.si_status;
			}
			++i;
		}
		if (!infos.si_code & CLD_KILLED || !infos.si_code & CLD_STOPPED)
			break ;
	}
	kill_child(forks, child_tab);
	return (last_ret);
}
