/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 15:54:11 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 14:49:55 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int				exist_var(t_var *v, char *cmd)
{
	while (v)
	{
		if (ft_strcmp(cmd, v->key) == 0)
			return (1);
		if (ft_sort_str(cmd, v->key) == 1)
			v = v->right;
		else
			v = v->left;
	}
	return (0);
}

int				exist_funct(t_funct *f, char *cmd)
{
	while (f)
	{
		if (ft_strcmp(cmd, f->key) == 0)
			return (1);
		if (ft_sort_str(cmd, f->key) == 1)
			f = f->right;
		else
			f = f->left;
	}
	return (0);
}
