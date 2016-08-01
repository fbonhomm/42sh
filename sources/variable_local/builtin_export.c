/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/11 19:55:24 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 19:37:59 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void			set_null(char ***tmp)
{
	(*tmp)[0] = NULL;
	(*tmp)[1] = NULL;
	(*tmp)[2] = NULL;
}

void			export_var(char *cmd)
{
	char		**tmp;

	tmp = (char**)malloc(sizeof(char*) * 3);
	set_null(&tmp);
	split_var(cmd, &tmp[0], &tmp[1]);
	if (pars_setenv(tmp) == -1)
		builtin_error("export: ", NULL);
	else
		builtin_setenv(tmp);
	ft_free_array(&tmp);
}

char			*return_value(char *cmd)
{
	t_var		*v;
	char		*tmp;

	tmp = NULL;
	v = g_tree->var;
	while (v)
	{
		if (ft_strcmp(cmd, v->key) == 0)
		{
			tmp = ft_strdup(v->value);
			break ;
		}
		if (ft_sort_str(cmd, v->key) == 1)
			v = v->right;
		else
			v = v->left;
	}
	return (tmp);
}

void			set_and_env(char *cmd)
{
	create_var(cmd);
	export_var(cmd);
}

int				builtin_export(char **cmd)
{
	int			ret;
	char		*value;
	char		*tmp;

	if (!(*cmd))
		return (-1);
	value = NULL;
	tmp = NULL;
	if ((ret = search_egal_export(*cmd)) == 0)
	{
		if (exist_var(g_tree->var, *cmd))
		{
			value = return_value(*cmd);
			tmp = ft_strjoin_mult(3, *cmd, "=", value);
			export_var(tmp);
		}
		else
			ft_print_str_endl(3, "export: ", *cmd, ": not found\n");
	}
	else if (ret == 1)
		set_and_env(*cmd);
	ft_free(&tmp);
	ft_free(&value);
	return (0);
}
