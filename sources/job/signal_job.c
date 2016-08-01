/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 15:45:17 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 17:10:12 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

void				new_job_ctrlz(t_job *j, int pid)
{
	j->pid = pid;
	j->status = 0;
	j->mode = 0;
	j->pgid = -1;
	j->id = -1;
	j->ctrlz = 1;
	j->command = NULL;
	j->next = NULL;
}

void				signal_job(t_shell *s, pid_t pid)
{
	t_job			*j;

	if (!conform_job(s))
		return ;
	j = (t_job*)malloc(sizeof(t_job));
	new_job_ctrlz(j, pid);
	if (s->first_job && s->first_job->id > 0)
		j->id = set_id(s->first_job);
	else
		j->id = 1;
	if (!s->first_job)
		s->first_job = j;
	else
		add_job(s, j);
	kill(pid, SIGTSTP);
	printf("[%d] %d\n", j->id, pid);
	if ((j->pgid = getpgid(j->pid)) <= 0)
		j->pgid = pid;
	setpgid(j->pid, j->pgid);
	setpgid(0, 0);
	setpgid(STDIN_FILENO, j->pgid);
	ft_sleep(10);
	set_status_job(j);
	if ((j->mode == STATUS_DONE) || (j->mode == STATUS_TERMINATED))
		print_done_job(j);
}
