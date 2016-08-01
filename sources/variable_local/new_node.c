/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:40:55 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 17:53:53 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

t_var			*new_node_var(char *key, char *value)
{
	t_var		*node;

	node = (t_var*)malloc(sizeof(t_var));
	node->key = ft_strdup(key);
	node->value = ft_strdup(value);
	node->left = NULL;
	node->right = NULL;
	return (node);
}

t_funct			*new_node_funct(char *key, char **content)
{
	t_funct		*node;

	node = (t_funct*)malloc(sizeof(t_funct));
	node->key = ft_strdup(key);
	node->content = ft_strdup_array(content);
	node->left = NULL;
	node->right = NULL;
	return (node);
}
