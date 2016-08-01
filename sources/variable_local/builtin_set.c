/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 17:43:50 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 14:31:10 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void			print_var(t_var *v)
{
	if (!v)
		return ;
	if (v->left)
		print_var(v->left);
	ft_print_str(4, v->key, "=", v->value, "\n");
	if (v->right)
		print_var(v->right);
}

void			print_funct(t_funct *f)
{
	int			i;

	i = 0;
	if (!f)
		return ;
	if (f->left)
		print_funct(f->left);
	ft_print_str(2, f->key, "()\n{\n");
	while (f->content[i])
		ft_print_str(3, "\t", f->content[i++], "\n");
	ft_putstr("}\n");
	if (f->right)
		print_funct(f->right);
}

int				secu_set(char *cmd)
{
	int			nbr;

	nbr = ft_parameter(2, cmd, ' ', '\t');
	if (nbr != 1)
		return (0);
	return (1);
}

int				builtin_set(char **cmd)
{
	int			ret;

	if (!(*cmd))
	{
		print_var(g_tree->var);
		print_funct(g_tree->funct);
	}
	else
	{
		if ((ret = search_egal_export(*cmd)))
			create_var(*cmd);
		else if (ret < 0)
			return (-1);
		else if (search_parenth(*cmd))
			create_funct(*cmd);
		else
			ft_print_str_endl(3, "set: ", *cmd, ": not found\n");
	}
	return (0);
}
