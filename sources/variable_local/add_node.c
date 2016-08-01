/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:40:55 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 19:32:59 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void			inside_loop_var(t_var **tmp, t_var **tmp_dir,
					t_var **tmp_node, t_var **node)
{
	(*tmp) = (*tmp_dir);
	if (!(*tmp))
		(*tmp_node) = (*node);
}

void			add_node_var(t_var **v, char *key, char *value)
{
	t_var		*node;
	t_var		*tmp;
	t_var		*tmp_node;

	node = new_node_var(key, value);
	tmp = *v;
	if (tmp)
	{
		while (tmp)
		{
			tmp_node = tmp;
			if (ft_sort_str(node->key, tmp->key) == 1)
				inside_loop_var(&tmp, &tmp->right, &tmp_node->right, &node);
			else
			{
				if (replace_node_var(tmp, node))
					break ;
				inside_loop_var(&tmp, &tmp->left, &tmp_node->left, &node);
			}
		}
	}
	else
		*v = node;
}

void			inside_loop_funct(t_funct **tmp, t_funct **tmp_dir,
					t_funct **tmp_node, t_funct **node)
{
	(*tmp) = (*tmp_dir);
	if (!(*tmp))
		(*tmp_node) = (*node);
}

void			add_node_funct(t_funct **f, char *key, char **content)
{
	t_funct		*node;
	t_funct		*tmp;
	t_funct		*tmp_node;

	node = new_node_funct(key, content);
	tmp = *f;
	if (tmp)
	{
		while (tmp)
		{
			tmp_node = tmp;
			if (ft_sort_str(node->key, tmp->key) == 1)
				inside_loop_funct(&tmp, &tmp->right, &tmp_node->right, &node);
			else
			{
				if (replace_node_funct(tmp, node))
					break ;
				inside_loop_funct(&tmp, &tmp->left, &tmp_node->left, &node);
			}
		}
	}
	else
		*f = node;
}
