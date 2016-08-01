/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:33:47 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/04 10:38:58 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_nbr_char(int n)
{
	int		len;

	len = 1;
	if (n < 0)
		len++;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	int		i;
	long	value;
	char	*p_str;

	i = ft_nbr_char(n) + 1;
	if (!(p_str = (char *)malloc(sizeof(*p_str) * i)))
		return (NULL);
	if ((value = n) < 0)
		value = -value;
	p_str[--i] = '\0';
	while (value / 10)
	{
		p_str[--i] = (value % 10) + '0';
		value = value / 10;
	}
	p_str[--i] = value + '0';
	if (n < 0)
		p_str[--i] = '-';
	return (p_str);
}
