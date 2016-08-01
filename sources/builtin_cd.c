/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:31:50 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/04 19:18:35 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static int			parser_cd(char *options, char **paths, int c)
{
	c = parser_opt(options, "PL");
	if (c != 0)
	{
		g_error = USCD;
		return (-1);
	}
	if (paths[0] != NULL && paths[1] != NULL)
	{
		g_error = EARGS;
		return (-1);
	}
	return (0);
}

static int			exec_cd3(char *path)
{
	if (parser_path(path, 'd', S_IXUSR) == -1)
		return (-1);
	if (modif_env("OLDPWD", get_env_val("PWD")) == -1
		|| modif_env("PWD", path) == -1)
		return (-1);
	return (chdir(path) == -1 ? int_error(EPERMS) : 0);
}

static int			exec_cd2(char *path, char *op, char buf[4096])
{
	if (path == NULL)
		return (-1);
	if (!op || (op && op[ft_strlen(op) - 1] != 'P')
		|| readlink(path, buf, 4096) < 0)
	{
		if (exec_cd3(path) == -1)
		{
			ft_strdel(&path);
			return (-1);
		}
	}
	else if (op[ft_strlen(op) - 1] == 'P' && readlink(path, buf, 4096) > 0)
	{
		ft_memmove(buf, buf - 1, 4094);
		buf[0] = '/';
		if (exec_cd3(buf) == -1)
		{
			ft_strdel(&path);
			return (-1);
		}
	}
	ft_strdel(&path);
	return (0);
}

static int			exec_cd(char *path, char *op)
{
	char	buf[4096];

	ft_bzero(buf, 4096);
	if (path[0] == '~')
	{
		if (convert_tilde(&path) == -1)
			return (-1);
		if (exec_cd2(modifpath(path), op, buf) == -1)
		{
			ft_strdel(&path);
			return (-1);
		}
		ft_strdel(&path);
		return (0);
	}
	if (ft_strcmp(path, "-") == 0)
	{
		path = get_env_val("OLDPWD");
		if (parser_path(path, 'd', S_IXUSR) == -1)
			return (g_error == ENONEX ? -1 : int_error(ENVO));
	}
	if (exec_cd2(modifpath(path), op, buf) == -1)
		return (-1);
	return (0);
}

int					builtin_cd(char **arg_list)
{
	char			*options;
	int				i;
	int				c;

	c = 0;
	i = 0;
	options = NULL;
	if ((options = get_options(arg_list)) == NULL && g_error != NULL)
		return (builtin_error("cd: ", options));
	arg_list = get_args(arg_list);
	if (parser_cd(options, arg_list, c) == -1)
	{
		ft_strdel(&options);
		return (builtin_error("cd: ", NULL));
	}
	if (arg_list[0] == NULL)
		arg_list[0] = "~";
	if (exec_cd(arg_list[0], options) == -1)
	{
		ft_strdel(&options);
		return (builtin_error("cd: ", arg_list[0]));
	}
	ft_strdel(&options);
	return (0);
}
