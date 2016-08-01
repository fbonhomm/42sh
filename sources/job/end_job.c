/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_job.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 21:26:40 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/05/29 13:36:00 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

t_job			*end_job(t_job *j)
{
	t_job		*tmp;

	tmp = j;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}