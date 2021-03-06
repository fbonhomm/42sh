/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_diff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:08:57 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/14 11:09:16 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_find_diff(int a, int b)
{
	if (a > b)
		return ((a - b) * -1);
	if (a < b)
		return (b - a);
	return (0);
}
