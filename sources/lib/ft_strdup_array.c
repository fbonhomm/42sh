/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 14:07:21 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/10/12 14:07:23 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int			ft_len_array(char **str)
{
	int		x;

	x = 0;
	while (str[x])
		x++;
	return (x);
}

char		**ft_strdup_array(char **tabl)
{
	char	**ret;
	int		i;

	i = 0;
	ret = NULL;
	if (!tabl)
		return (NULL);
	ret = (char**)malloc(sizeof(char*) * (ft_len_array(tabl) + 2));
	while (tabl[i])
	{
		ret[i] = ft_strdup(tabl[i]);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
