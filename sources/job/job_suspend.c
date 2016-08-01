/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job_suspend.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 14:56:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 20:41:05 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

char		***split_job(char *cmd)
{
	int		i;
	char	**tmp;
	char	***tabl;

	i = 0;
	tmp = ft_strsplit(cmd, '&');
	while (tmp[i])
		i++;
	tabl = (char***)malloc(sizeof(char*) * (i + 1));
	i = -1;
	while (tmp[++i])
		tabl[i] = ft_split(tmp[i], ' ', '\t');
	tabl[i] = NULL;
	ft_free_array(&tmp);
	return (tabl);
}

int			job_suspend(char **toto)
{
	int		i;
	char	***tabl;
	char	*cmd;
	t_shell	*s;

	cmd = ft_tab_to_str(toto, ' ');
	if (!(search_ampersand(cmd)))
		return (-1);
	s = g_shell;
	i = -1;
	tabl = split_job(cmd);
	while (tabl[++i])
		launch_job(s, tabl[i]);
	i = -1;
	while (tabl[++i])
		ft_free_array(&tabl[i]);
	free(tabl);
	return (0);
}
