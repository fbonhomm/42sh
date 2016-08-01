/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:39:37 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/26 10:55:52 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void			init_set(char **env)
{
	g_tree = (t_tree*)malloc(sizeof(t_tree));
	g_tree->var = (t_var*)malloc(sizeof(t_var));
	g_tree->funct = (t_funct*)malloc(sizeof(t_funct));
	g_tree->var = NULL;
	g_tree->funct = NULL;
	add_env(&g_tree->var, env);
}
