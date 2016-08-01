/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 19:55:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 19:24:41 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int				builtin_unset(char **cmd)
{
	if (!(*cmd))
		return (-1);
	if (exist_var(g_tree->var, *cmd))
		g_tree->var = delete_node_var(g_tree->var, *cmd);
	else if (exist_funct(g_tree->funct, *cmd))
		g_tree->funct = delete_node_funct(g_tree->funct, *cmd);
	else
		ft_print_str_endl(3, "unset: ", *cmd, ": not found\n");
	return (0);
}
