/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/28 15:26:36 by ksoulard          #+#    #+#             */
/*   Updated: 2016/01/11 16:20:58 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long		ft_nblen(long long n)
{
	long long	nb;

	nb = 0;
	while (n != 0)
	{
		n = n / 10;
		nb++;
	}
	return (nb == 0 ? 1 : nb);
}