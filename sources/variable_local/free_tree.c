/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 20:55:48 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 19:38:48 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void			free_tree(void)
{
	if (g_tree->var)
		free_tree_var(&g_tree->var);
	if (g_tree->funct)
		free_tree_funct(&g_tree->funct);
	free(g_tree);
}

void			free_tree_var(t_var **v)
{
	t_var		*tmp;

	tmp = *v;
	if (!v)
		return ;
	if (tmp->left)
		free_tree_var(&tmp->left);
	if (tmp->right)
		free_tree_var(&tmp->right);
	ft_free(&tmp->key);
	ft_free(&tmp->value);
	free(tmp);
	*v = NULL;
}

void			free_tree_funct(t_funct **f)
{
	t_funct		*tmp;

	tmp = *f;
	if (!f)
		return ;
	if (tmp->left)
		free_tree_funct(&tmp->left);
	if (tmp->right)
		free_tree_funct(&tmp->right);
	ft_free(&tmp->key);
	ft_free_array(&tmp->content);
	free(tmp);
	*f = NULL;
}
