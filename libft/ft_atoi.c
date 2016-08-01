/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:32:40 by ksoulard          #+#    #+#             */
/*   Updated: 2016/02/11 11:19:40 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		index;
	int		value;

	index = 1;
	value = 0;
	if (str == NULL)
		return (0);
	while ((*str == 32 || (*str >= 9 && *str <= 13)))
		str++;
	if (*str == '-')
	{
		str++;
		index = -1;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		value = value * 10 + (*str++ - '0');
	return (value * index);
}
