/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arealpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 08:18:09 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/08 08:18:14 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arealpha(char *str)
{
	if (!str || ft_strcmp(str, "") == 0)
		return (0);
	while (*str)
	{
		if (!ft_isalpha(*str++))
			return (0);
	}
	return (1);
}
