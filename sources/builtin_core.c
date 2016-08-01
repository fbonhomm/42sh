/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:36:30 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/14 17:36:42 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int				execve_builtin(char **arg_list)
{
	t_hash		**hash;
	char		*bin;

	hash = g_memory(S_HASH, 0);
	if (ft_strchr(arg_list[0], '/') == NULL)
	{
		if (hash == NULL)
		{
			g_error = EMANYF;
			exit(127);
		}
		if ((bin = ft_strjoin(get_path_hash(arg_list[0], hash), arg_list[0]))
		== NULL)
		{
			g_error = ENONEX;
			error("env");
			exit(EXIT_FAILURE);
		}
	}
	else
		bin = arg_list[0];
	execve(bin, arg_list, g_env);
	g_error = EMANYF;
	exit(127);
	return (-1);
}

static int		builtin_core2(int (*g_func_builtin[NBR_BUILTIN])(char **),
				char *g_builtin[NBR_BUILTIN], t_cmd *cmd)
{
	int			i;

	i = 0;
	while (g_builtin[i])
	{
		if (ft_strcmp(cmd->arg_list[0], g_builtin[i]) == 0)
		{
			if (g_func_builtin[i](&cmd->arg_list[1]) == -1)
				return (-1);
			break ;
		}
		++i;
	}
	return (0);
}

int				builtin_core(t_cmd *cmd)
{
	static int		(*g_func_builtin[NBR_BUILTIN])(char **) = {
			builtin_cd,
			builtin_setenv,
			builtin_exit,
			builtin_unsetenv,
			builtin_env,
			builtin_echo,
			builtin_set,
			builtin_unset,
			builtin_export
		};
	static char		*g_builtin[NBR_BUILTIN] = {
			"cd",
			"setenv",
			"exit",
			"unsetenv",
			"env",
			"echo",
			"set",
			"unset",
			"export"
		};

	return (builtin_core2(g_func_builtin, g_builtin, cmd));
}
