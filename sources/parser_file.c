/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:33:22 by ksoulard          #+#    #+#             */
/*   Updated: 2016/07/25 16:55:53 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int				f_cpy(int fd1, int fd2)
{
	int			ret;
	char		s;

	while ((ret = read(fd1, &s, 1)) > 0)
	{
		if (write(fd2, &s, 1) == -1)
		{
			g_error = EWRITE;
			return (-1);
		}
	}
	if (ret == -1)
		g_error = EREAD;
	return (ret);
}

int				f_isexec(char *path, short mode)
{
	if (mode & S_IRUSR && access(path, R_OK) == -1)
		g_error = EPERMS;
	else if (mode & S_IXUSR && access(path, X_OK) == -1)
		g_error = EPERMS;
	else if (mode & S_IWUSR && access(path, W_OK) == -1)
		g_error = EPERMS;
	else
		return (0);
	return (-1);
}

int				f_type2(struct stat st, char type)
{
	if (type == '-' && !S_ISREG(st.st_mode))
		g_error = SREGG;
	else if (type == 'd' && !S_ISDIR(st.st_mode))
		g_error = SDIRR;
	else if (type == 'l' && !S_ISLNK(st.st_mode))
		g_error = SLNKK;
	else if (type == 'c' && !S_ISCHR(st.st_mode))
		g_error = SCHRR;
	else if (type == 'f' && !S_ISFIFO(st.st_mode))
		g_error = SFIFOO;
	else if (type == 'b' && !S_ISBLK(st.st_mode))
		g_error = SBLOCKK;
	else if (type == 's' && !S_ISSOCK(st.st_mode))
		g_error = SSOCKET;
	else
		return (0);
	return (-1);
}

int				f_type(char *path, char type)
{
	struct stat	st;

	if (type == 'l')
	{
		if (lstat(path, &st) == -1)
		{
			g_error = EPERMS;
			return (-1);
		}
	}
	else
	{
		if (stat(path, &st) == -1)
		{
			g_error = EPERMS;
			return (-1);
		}
	}
	return (f_type2(st, type));
}

int				f_testfile(char *path, char *file, char type, short mode)
{
	char		*tmp;

	if (file == NULL)
		tmp = ft_strdup(path);
	else
		tmp = ft_strjoin(path, file);
	if (tmp == NULL)
	{
		g_error = EALLOC;
		return (-1);
	}
	if (access(tmp, F_OK) == -1)
	{
		ft_strdel(&tmp);
		g_error = ENONEX;
		return (-1);
	}
	if (f_type(tmp, type) == -1 || f_isexec(tmp, mode) == -1)
	{
		ft_strdel(&tmp);
		return (-1);
	}
	ft_strdel(&tmp);
	return (0);
}
