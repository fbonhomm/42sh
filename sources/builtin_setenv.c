/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:32:27 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/14 17:33:14 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int			pars_setenv(char **args)
{
	int		i;

	i = 0;
	if (ft_strchr(args[0], '=') != NULL)
	{
		g_error = ESYN;
		return (-1);
	}
	if (args[1] != NULL && args[2] != NULL)
	{
		g_error = EARGS;
		return (-1);
	}
	return (0);
}

static int	exec_setenv(char **args)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	line = get_env_line(args[0]);
	if ((tmp = strcatstr(args[0], args[1], "=")) == NULL)
		return (int_error(EALLOC));
	if (line == NULL)
		expand_env(tmp);
	else if (modif_env(args[0], args[1]) == -1)
		return (-1);
	if (ft_strcmp(args[0], "PATH") == 0)
	{
		free_brain(S_HASH);
		g_memory(S_HASH, -1);
		if (create_hashtab() == -1)
		{
			if (g_error == EALLOC)
				return (-1);
		}
	}
	ft_strdel(&tmp);
	return (0);
}

int			builtin_setenv(char **arg_list)
{
	if (arg_list[0] == NULL)
	{
		ft_print_tab(g_env);
		return (0);
	}
	if (pars_setenv(arg_list) == -1)
		return (builtin_error("setenv: ", NULL));
	if (exec_setenv(arg_list) == -1)
		return (-1);
	return (0);
}
