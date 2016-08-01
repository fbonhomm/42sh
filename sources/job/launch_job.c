/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 18:36:19 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 16:54:22 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

int					conform_job(t_shell *s)
{
	if (!s)
		return (-1);
	if (s && nbr_jobs(s) >= MAX_JOB)
	{
		ft_putstr_fd(" - Maximum number of jobs\n", 2);
		return (-1);
	}
	return (1);
}

void				launch_parent(t_job *j, pid_t child)
{
	j->pid = child;
	j->pgid = child;
	setpgid(child, j->pgid);
	print_job(j);
}

void				launch_job(t_shell *s, char **cmd)
{
	t_job			*j;
	pid_t			child;

	if (!conform_job(s))
		return ;
	j = (t_job*)malloc(sizeof(t_job));
	j->command = ft_strdup_array(cmd);
	new_job(j);
	j->ctrlz = 0;
	j->id = (s->first_job && s->first_job->id > 0) ? set_id(s->first_job) : 1;
	(!s->first_job) ? s->first_job = j : add_job(s, j);
	if ((child = fork()) < 0)
	{
		ft_perror("fork");
		return ;
	}
	if (child == 0)
		launch_process(j);
	launch_parent(j, child);
}
