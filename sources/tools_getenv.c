/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_getenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:35:58 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:35:59 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

char		*get_paths(char *paths)
{
	int		fd;
	int		ret;
	char	*line;
	char	*tmp;

	if (parser_path("/etc/paths", '-', S_IRUSR) == -1)
		return (NULL);
	fd = open("/etc/paths", O_RDONLY);
	paths = ft_strdup("PATH=");
	while (paths != NULL && (ret = get_next_line(fd, &line) > 0))
	{
		tmp = paths;
		paths = strcatstr(paths, ":", line);
		ft_strdel(&tmp);
		ft_strdel(&line);
	}
	if (ret == -1 || paths == NULL)
	{
		if (paths == NULL)
			g_error = EALLOC;
		ft_strdel(&paths);
	}
	paths[ft_strlen(paths) - 1] = '\0';
	return (paths);
}

char		*get_pwd(char *pwd)
{
	char	*tmp;

	tmp = NULL;
	tmp = getcwd(tmp, 0);
	if (tmp == NULL)
		pwd = ft_strdup("PWD=.");
	else
		pwd = ft_strjoin("PWD=", tmp);
	ft_strdel(&tmp);
	if (pwd == NULL)
		g_error = EALLOC;
	return (pwd);
}

char		*get_oldpwd(char *oldpwd)
{
	char	*tmp;

	tmp = NULL;
	tmp = getcwd(tmp, 0);
	if (tmp == NULL)
		oldpwd = ft_strdup("OLDPWD=.");
	else
		oldpwd = ft_strjoin("OLDPWD=", tmp);
	ft_strdel(&tmp);
	if (oldpwd == NULL)
		g_error = EALLOC;
	return (oldpwd);
}

char		*get_shlvl(char *shlvl)
{
	shlvl = strcatstr("SHLVL", "1", "=");
	if (shlvl == NULL)
		g_error = EALLOC;
	return (shlvl);
}

char		*(*g_get_env(char *var))(char *)
{
	char	*(*vars[5])(char *);

	vars[0] = get_paths;
	vars[1] = get_shlvl;
	vars[2] = get_oldpwd;
	vars[3] = get_pwd;
	vars[4] = NULL;
	if (ft_strcmp(var, "PATH") == 0)
		return (vars[0]);
	else if (ft_strcmp(var, "PWD") == 0)
		return (vars[3]);
	else if (ft_strcmp(var, "OLDPWD") == 0)
		return (vars[2]);
	else
		return (vars[1]);
}
