/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:32:35 by ksoulard          #+#    #+#             */
/*   Updated: 2016/07/25 18:36:57 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static int	pars_unsetenv(char *arg)
{
	if (arg == NULL)
	{
		g_error = EARG;
		return (-1);
	}
	return (0);
}

static int	exec_unsetenv(char **args)
{
	int		i;
	char	*line;
	char	**tmp;

	i = 0;
	while (args[i])
	{
		line = get_env_line(args[i]);
		if (line != NULL)
		{
			if (ft_strcmp(args[i], "PATH") == 0)
				free_brain(S_HASH);
			tmp = g_env;
			g_env = ft_delline(g_env, line);
			ft_freetab(tmp);
			if (g_env == NULL)
			{
				g_error = EALLOC;
				return (-1);
			}
		}
		i++;
	}
	return (0);
}

int			builtin_unsetenv(char **arg_list)
{
	if (pars_unsetenv(arg_list[0]) == -1)
		return (builtin_error("unsetenv: ", NULL));
	if (exec_unsetenv(arg_list) == -1)
		return (-1);
	return (0);
}
