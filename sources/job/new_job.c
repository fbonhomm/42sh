/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_job.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 18:28:22 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/05/31 16:17:45 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

void			new_job(t_job *j)
{
	j->pid = -1;
	j->status = 0;
	j->mode = 0;
	j->pgid = -1;
	j->id = -1;
	j->next = NULL;
}