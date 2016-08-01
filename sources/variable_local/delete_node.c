/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 23:22:00 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/15 23:59:28 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

t_var			*min_value_var(t_var *v)
{
	t_var		*tmp;

	tmp = v;
	while (tmp->left != NULL)
		tmp = v->left;
	return (tmp);
}

t_funct			*min_value_funct(t_funct *f)
{
	t_funct		*tmp;

	tmp = f;
	while (tmp->left != NULL)
		tmp = f->left;
	return (tmp);
}

t_var			*delete_node_var(t_var *v, char *command)
{
	t_var		*tmp;

	tmp = NULL;
	if (v == NULL)
		return (v);
	if (ft_sort_str(command, v->key) == 1)
		v->right = delete_node_var(v->right, command);
	else if (ft_strcmp(command, v->key) != 0)
		v->left = delete_node_var(v->left, command);
	else
	{
		if (v->left == NULL)
			return ((tmp = free_node_var(v->right, v, tmp)));
		else if (v->right == NULL)
			return ((tmp = free_node_var(v->left, v, tmp)));
		tmp = min_value_var(v->right);
		ft_free(&v->key);
		ft_free(&v->value);
		v->key = ft_strdup(tmp->key);
		v->value = ft_strdup(tmp->value);
		v->right = delete_node_var(v->right, tmp->key);
	}
	return (v);
}

t_funct			*delete_node_funct(t_funct *f, char *command)
{
	t_funct		*tmp;

	tmp = NULL;
	if (f == NULL)
		return (f);
	if (ft_sort_str(command, f->key) == 1)
		f->right = delete_node_funct(f->right, command);
	else if (ft_strcmp(command, f->key) != 0)
		f->left = delete_node_funct(f->left, command);
	else
	{
		if (f->left == NULL)
			return ((tmp = free_node_funct(f->right, f, tmp)));
		else if (f->right == NULL)
			return ((tmp = free_node_funct(f->left, f, tmp)));
		tmp = min_value_funct(f->right);
		ft_free(&f->key);
		ft_free_array(&f->content);
		f->key = ft_strdup(tmp->key);
		f->content = ft_strdup_array(tmp->content);
		f->right = delete_node_funct(f->right, tmp->key);
	}
	return (f);
}
