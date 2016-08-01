/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:33:43 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/03 23:42:34 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static char			*modifpath2(char **tb, char *new)
{
	char			*s;
	int				i;

	i = -1;
	while (tb[++i] != NULL && new != NULL)
	{
		if (ft_strcmp(tb[i], "..") == 0)
		{
			s = ft_strrchr(new, '/');
			if (s == new)
				*(s + 1) = '\0';
			else if (s != NULL)
				*s = '\0';
		}
		else if (ft_strcmp(tb[i], ".") != 0)
		{
			s = new;
			if (ft_strcmp(new, "/") == 0)
				new = ft_strjoin(new, tb[i]);
			else
				new = strcatstr(new, tb[i], "/");
			ft_strdel(&s);
		}
	}
	return (new);
}

char				*modifpath(char *path)
{
	char			*new;
	char			**tb;

	if (path == NULL || parser_path(path, 'd', S_IXUSR) == -1)
		return (NULL);
	if ((tb = ft_strsplit(path, '/')) == NULL)
	{
		g_error = EALLOC;
		return (NULL);
	}
	new = path[0] == '/' ? ft_strdup("/") : getcwd(NULL, 0);
	if (new == NULL)
	{
		ft_freetab(tb);
		g_error = EDIRPRES;
		return (NULL);
	}
	new = modifpath2(tb, new);
	ft_freetab(tb);
	if (new == NULL)
		g_error = EALLOC;
	return (new);
}

static int			veriflenpath(char **paths, char *path)
{
	int				i;

	i = 0;
	if (path == NULL)
		return (0);
	if (ft_strlen(path) > PATH_MAX_MIN)
	{
		g_error = ELPATH;
		return (-1);
	}
	while (paths[i] != NULL)
	{
		if (ft_strlen(paths[i]) > NAME_MAX_MIN)
		{
			g_error = ENAMEL;
			return (-1);
		}
		i++;
	}
	return (0);
}

static int			exec_parserpath(char **paths, char **oldpath,
					char type, short mode)
{
	int				i;
	char			*tmp;
	char			ttype;
	short			mmode;

	i = 0;
	tmp = NULL;
	while (paths[i])
	{
		ttype = paths[i + 1] == NULL ? type : 'd';
		mmode = paths[i + 1] != NULL ? S_IXUSR : mode;
		if (f_testfile(*oldpath, paths[i], ttype, mmode) == -1)
		{
			ft_strdel(&tmp);
			return (-1);
		}
		tmp = *oldpath;
		*oldpath = strcatstr(*oldpath, "/", paths[i]);
		ft_strdel(&tmp);
		if (*oldpath == NULL)
			return (int_error(EALLOC));
		i++;
	}
	return (0);
}

int					parser_path(char *path, char type, short mode)
{
	char			*oldpath;
	char			**paths;

	paths = ft_strsplit(path, '/');
	if (path == NULL || ft_strcmp(path, "") == 0)
		return (int_error(ENONEX));
	if (paths && (paths[0] != NULL && path[0] != '/'))
		oldpath = ft_strdup("./");
	else
		oldpath = ft_strdup("/");
	if (veriflenpath(paths, path) == -1)
		return (-1);
	if (exec_parserpath(paths, &oldpath, type, mode) == -1
		|| !paths || !oldpath)
	{
		ft_freetab(paths);
		ft_strdel(&oldpath);
		return (-1);
	}
	ft_freetab(paths);
	ft_strdel(&oldpath);
	return (0);
}
