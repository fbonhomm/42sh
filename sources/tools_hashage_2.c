/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_hashage_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:36:02 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/14 17:38:43 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int					count_bin2(char *path, int nb_bin)
{
	DIR				*dir;
	struct dirent	*files;

	if ((dir = opendir(path)) == NULL)
	{
		g_error = EOPEN;
		return (-1);
	}
	while ((files = readdir(dir)) != NULL)
	{
		if (files->d_name[0] != '.')
			++nb_bin;
	}
	closedir(dir);
	return (nb_bin);
}

int					count_bin(char **paths)
{
	int				i;
	static int		nb_bin;

	if (paths == NULL)
		return (nb_bin);
	i = 0;
	nb_bin = 0;
	while (paths[i])
	{
		if (parser_path(paths[i], 'd', S_IRUSR) == -1)
			return (-1);
		nb_bin = count_bin2(paths[i], nb_bin);
		++i;
	}
	return (nb_bin);
}

int					hashage(char *name)
{
	int		i;

	i = 0;
	while (*name != '\0')
	{
		i = i + *name + ((i % 4) * 128);
		name++;
	}
	return (i % count_bin(NULL));
}

char				*get_path_hash(char *name, t_hash **hash)
{
	t_lhash	*lhash;

	lhash = hash[hashage(name)]->lhash;
	while (lhash != NULL)
	{
		if (ft_strcmp(name, lhash->name) == 0)
			return (lhash->path);
		lhash = lhash->next;
	}
	return (NULL);
}
