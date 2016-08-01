/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_job.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:30:38 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 18:39:23 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

void			print_status(int status)
{
	if (status == STATUS_SUSPENDED)
		ft_putstr(" Stopped ");
	else if (status == STATUS_DONE)
		ft_putstr(" Done ");
	else if (status == STATUS_TERMINATED)
		ft_putstr(" Terminated ");
	else if (status == STATUS_RUNNING)
		ft_putstr(" Running ");
}

void			print_jobs(t_job *j)
{
	ft_putchar('[');
	ft_putnbr(j->id);
	ft_putstr("] ");
	ft_putnbr(j->pid);
	print_status(j->mode);
	ft_put_array(j->command, " ");
	ft_putchar('\n');
}

int				secu_job(t_shell *s)
{
	if (!s->first_job)
	{
		ft_putstr_fd("jobs: no job\n", 2);
		return (-1);
	}
	return (0);
}

int				builtin_job(char **cmd)
{
	t_job		*j;
	t_shell		*s;

	if (*cmd)
	{
		ft_putstr_fd("jobs: no prameter\n", 2);
		return (-1);
	}
	s = g_shell;
	if ((secu_job(s)) == -1)
		return (-1);
	j = s->first_job;
	while (j)
	{
		set_status_job(j);
		if ((j->mode == STATUS_DONE) || (j->mode == STATUS_TERMINATED))
			remove_job(j, s);
		else
			print_jobs(j);
		j = j->next;
	}
	if (g_shell->first_job == NULL)
		ft_putstr_fd("jobs: no job\n", 2);
	return (0);
}
