/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:39:37 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 13:41:27 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void			init_set(char **env)
{
	g_tree = (t_tree*)malloc(sizeof(t_tree));
	g_tree->var = NULL;
	g_tree->funct = NULL;
	add_env(&g_tree->var, env);
}
