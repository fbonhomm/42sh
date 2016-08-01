/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:01:56 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 20:35:52 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int				secu_var(char *cmd)
{
	int			nbr;

	nbr = ft_parameter(2, cmd, ' ', '\t');
	if ((nbr != 1) || (!cmd) || (!conform_set_var(cmd)))
		return (0);
	return (1);
}

int				create_var(char *cmd)
{
	char		*key;
	char		*value;

	if (!(secu_var(cmd)))
		return (-1);
	key = NULL;
	value = NULL;
	split_var(cmd, &key, &value);
	add_node_var(&g_tree->var, key, value);
	update_in_env(key, value);
	ft_free(&key);
	ft_free(&value);
	return (0);
}
