/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:32:14 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:32:15 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static int	parser_env(char *options)
{
	char	c;

	c = parser_opt(options, "i");
	if (c != 0)
	{
		g_error = USENV;
		return (-1);
	}
	return (0);
}

static int	exec_env(char **arg_list)
{
	int		i;
	char	*s;
	char	*args[3];

	i = 0;
	while (arg_list[i] != NULL)
	{
		if ((s = ft_strchr(arg_list[i], '=')) == NULL)
			break ;
		*s = '\0';
		args[0] = arg_list[i];
		args[1] = ++s;
		args[2] = NULL;
		if (builtin_setenv(args) == -1)
			return (-1);
		*(--s) = '=';
		i++;
	}
	if (arg_list[i] == NULL)
	{
		ft_print_tab(g_env);
		exit(EXIT_SUCCESS);
	}
	return (execve_builtin(&arg_list[i]) == -1 && g_error != NULL ? -1 : 0);
}

int			builtin_env(char **arg_list)
{
	char	*options;
	int		i;

	i = 0;
	options = get_options(arg_list);
	if (options)
		while (g_env[i] != NULL)
		{
			ft_strdel(&g_env[i]);
			++i;
		}
	ft_strdel(&options);
	arg_list = get_args(arg_list);
	if (parser_env(options) == -1)
	{
		error("env: ");
		exit(EXIT_FAILURE);
	}
	if (exec_env(arg_list) == -1)
	{
		error("env: ");
		exit(EXIT_FAILURE);
	}
	return (0);
}
