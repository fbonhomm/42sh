/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_in_local.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:35:48 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 19:38:58 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int				search_in_local(char **tmp, char **rest, char **s)
{
	t_var		*v;
	char		*value;

	v = g_tree->var;
	if (exist_var(v, *tmp))
	{
		value = return_value(*tmp);
		*s = ft_strjoin(value, *rest);
		ft_strdel(tmp);
		ft_strdel(rest);
		ft_strdel(&value);
		return (1);
	}
	return (0);
}
