/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_job.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 17:30:15 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 16:53:39 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

void					init_job()
{
	g_shell = NULL;
	if (isatty(STDIN_FILENO))
	{
		g_shell = (t_shell*)malloc(sizeof(t_shell));
		signal(SIGTTIN, SIG_IGN);
		signal(SIGTTOU, SIG_IGN);
		g_shell->pgid = getpid();
		if (setpgid(g_shell->pgid, g_shell->pgid) < 0)
		{
			ft_perror("setpgid");
			g_shell = NULL;
		}
		tcsetpgrp(STDIN_FILENO, g_shell->pgid);
		tcgetattr(STDIN_FILENO, &g_shell->term);
		g_shell->first_job = NULL;
	}
}
