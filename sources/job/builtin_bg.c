/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_bg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 20:55:57 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 17:40:19 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

t_job			*secu_bg(t_shell *s, char *cmd, pid_t *pid)
{
	t_job		*j;

	if (!(cmd))
		*pid = 0;
	else
		*pid = ft_atoi(cmd);
	if (!s->first_job)
		return (print_and_return("bg: no job\n"));
	j = (*pid == 0) ? end_job(s->first_job) : search_pid(*pid, s->first_job);
	if (!j)
		return (print_and_return("bg: PID not found\n"));
	return (j);
}

int				builtin_bg(char **cmd)
{
	t_job		*j;
	t_shell		*s;
	pid_t		pid;

	s = g_shell;
	if (!(j = secu_bg(s, *cmd, &pid)))
		return (-1);
	set_status_job(j);
	if ((j->mode == STATUS_DONE) || (j->mode == STATUS_TERMINATED))
		remove_job(j, s);
	if (j->mode != STATUS_RUNNING)
	{
		if (kill(-(j->pgid), SIGCONT) < 0)
			ft_perror("kill");
		print_job(j);
		set_status_job(j);
		if ((j->mode == STATUS_DONE) || (j->mode == STATUS_TERMINATED))
			remove_job(j, s);
	}
	else
		ft_putstr("bg: job run in background\n");
	return (0);
}
