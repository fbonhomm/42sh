/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:37:33 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:37:34 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_pow(int x, int y)
{
	int				result;

	result = 1;
	if (y == 0)
		return (1);
	while (y)
	{
		result = result * x;
		y--;
	}
	return (result);
}
