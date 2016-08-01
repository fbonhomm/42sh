/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_parenth.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:55:53 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/24 14:00:59 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int				search_parenth(char *str)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] == '(') || (str[i] == ')'))
			j++;
		i++;
	}
	return (j);
}