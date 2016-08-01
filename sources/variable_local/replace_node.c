/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:40:55 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 17:24:31 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int				replace_node_var(t_var *tmp, t_var *node)
{
	if (strcmp(tmp->key, node->key) == 0)
	{
		ft_free(&tmp->value);
		tmp->value = ft_strdup(node->value);
		ft_free(&node->key);
		ft_free(&node->value);
		free(node);
		node = NULL;
		return (1);
	}
	else
		return (0);
}

int				replace_node_funct(t_funct *tmp, t_funct *node)
{
	if (strcmp(tmp->key, node->key) == 0)
	{
		ft_free_array(&tmp->content);
		tmp->content = ft_strdup_array(node->content);
		ft_free(&node->key);
		ft_free_array(&node->content);
		free(node);
		node = NULL;
		return (1);
	}
	else
		return (0);
}
