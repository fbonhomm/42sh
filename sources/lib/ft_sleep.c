/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 23:49:33 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 16:56:34 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_sleep(long miliseconds)
{
	struct timespec	req;
	struct timespec	rem;

	if (miliseconds > 999)
	{
		req.tv_sec = (int)(miliseconds / 1000);
		req.tv_nsec = (miliseconds - ((long)req.tv_sec * 1000)) * 1000000;
	}
	else
	{
		req.tv_sec = 0;
		req.tv_nsec = miliseconds * 1000000;
	}
	return (nanosleep(&req, &rem));
}
