/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_pid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 20:55:57 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/01 16:11:53 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

t_job		*search_pid(int pid, t_job *j)
{
	t_job	*tmp;

	tmp = j;
	while (tmp)
	{
		if (tmp->pid == pid)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
