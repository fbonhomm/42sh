/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_job.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 22:36:41 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/16 00:23:40 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

void			add_job(t_shell *s, t_job *j)
{
	t_job		*tmp;

	tmp = s->first_job;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = j;
}
