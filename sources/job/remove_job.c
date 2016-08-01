/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_job.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 16:58:04 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 16:54:52 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

void			remove_first_job(t_job *j, t_job *tmp, t_shell *s)
{
	if (tmp->next)
		s->first_job = tmp->next;
	else
		s->first_job = NULL;
	ft_free_array(&j->command);
	free(j);
}

void			remove_job(t_job *j, t_shell *s)
{
	t_job		*tmp;

	tmp = s->first_job;
	if (tmp->id == j->id)
		remove_first_job(j, tmp, s);
	else
	{
		while (tmp->next)
		{
			if (tmp->next->id == j->id)
			{
				if (j->next)
					tmp->next = j->next;
				else
					tmp->next = NULL;
				ft_free_array(&j->command);
				free(j);
				return ;
			}
			tmp = tmp->next;
		}
	}
}
