/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_fg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 20:55:57 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 18:37:11 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

t_job				*secu_fg(t_shell *s, char *cmd, pid_t *pid)
{
	t_job			*j;

	if (!(cmd))
		*pid = 0;
	else
		*pid = ft_atoi(cmd);
	if (!s->first_job)
		return (print_and_return("fg: no job\n"));
	j = (*pid == 0) ? end_job(s->first_job) : search_pid(*pid, s->first_job);
	if (!j)
		return (print_and_return("fg: PID not found\n"));
	return (j);
}

int					builtin_fg(char **cmd)
{
	t_job			*j;
	t_shell			*s;
	pid_t			pid;

	s = g_shell;
	if (!(j = secu_fg(s, *cmd, &pid)))
		return (-1);
	set_status_job(j);
	while ((j->mode == STATUS_DONE) || (j->mode == STATUS_TERMINATED))
	{
		remove_job(j, s);
		set_status_job(j);
	}
	ft_put_array(j->command, " ");
	ft_putchar('\n');
	tcsetpgrp(STDIN_FILENO, j->pgid);
	if (kill(-(j->pgid), SIGCONT) < 0)
		ft_perror("kill");
	ft_sleep(10);
	status_job(j);
	tcsetpgrp(STDIN_FILENO, getpid());
	tcsetattr(STDIN_FILENO, TCSADRAIN, &s->term);
	remove_job(j, s);
	return (0);
}
