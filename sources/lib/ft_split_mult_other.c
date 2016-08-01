/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mult_other.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 16:47:39 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 18:59:32 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_search_false(char const *s, char *c, int i)
{
	int		k;

	k = 0;
	while (c[k] && s[i])
	{
		if (c[k] == s[i])
		{
			k = 0;
			i++;
		}
		else
			k++;
	}
	return (i);
}

int			ft_search_true(char const *s, char *c, int i)
{
	int		k;
	int		nb;

	k = 0;
	nb = 0;
	while (s[i])
	{
		while (c[k])
		{
			if (c[k] == s[i])
				return (nb);
			k++;
		}
		nb++;
		i++;
		k = 0;
	}
	return (nb);
}
