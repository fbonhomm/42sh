/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_status_job.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 20:22:29 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 16:55:14 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

int				set_mode(t_job *j)
{
	char		*str;

	if (WSTOPSIG(j->status))
		j->mode = STATUS_SUSPENDED;
	else if (WIFSIGNALED(j->status))
	{
		j->mode = STATUS_TERMINATED;
		str = ft_itoa(WTERMSIG(j->status));
		ft_print_str_endl(3, "\nTerminated :", str, "\n");
		ft_free(&str);
		return (-1);
	}
	else if (WIFCONTINUED(j->status))
		j->mode = STATUS_CONTINUED;
	else if (WIFEXITED(j->status))
	{
		if (kill(j->pid, 0) != 0)
			j->mode = STATUS_DONE;
		else
			j->mode = STATUS_RUNNING;
	}
	return (0);
}

void			status_job(t_job *j)
{
	j->status = 0;
	waitpid(-(j->pgid), &j->status, WUNTRACED);
	set_mode(j);
}

void			set_status_job(t_job *j)
{
	pid_t		pid;

	j->status = 0;
	pid = 0;
	while ((pid = waitpid(-(j->pgid), &j->status, WUNTRACED | WNOHANG)) > 0)
	{
		if (pid == j->pid)
		{
			set_mode(j);
			return ;
		}
	}
	if (kill(j->pid, 0) != 0)
		j->mode = STATUS_DONE;
}

void			set_status_jobs(t_job *j)
{
	pid_t		pid;
	t_job		*t;

	j->status = 0;
	pid = 0;
	t = j;
	while (t)
	{
		if ((pid = waitpid(-(t->pgid), &t->status, WUNTRACED | WNOHANG)) > 0)
		{
			while (t && pid != t->pid)
				t = t->next;
			if (!t)
				return ;
			set_mode(t);
		}
		if (kill(t->pid, 0) != 0)
			t->mode = STATUS_DONE;
		t = t->next;
	}
}
