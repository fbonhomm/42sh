/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_egal_export.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 17:04:29 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/24 16:56:01 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int			err_env(int ret)
{
	ft_putstr_fd("Variable name must begin with a letter\n", 2);
	return (ret);
}

int			search_egal_export(char *str)
{
	int		i;
	int		booleen;

	i = -1;
	booleen = 0;
	while (str[++i])
	{
		if (str[i] == '=')
			booleen = 1;
	}
	if (!booleen)
		return (0);
	if ((!(ft_isalpha(str[0]))) && (str[0] != '_'))
		return (err_env(-1));
	i = -1;
	while (str[++i])
	{
		if ((!(ft_isalnum(str[i]))) && (str[i] != '_') && (!booleen))
			return (err_env(-1));
	}
	return (1);
}
