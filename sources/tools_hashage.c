/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_hashage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:36:08 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/03 14:16:10 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

t_lhash				*add_lhash(t_lhash **begin_lhash, char *name, char *path)
{
	t_lhash			*tmp;
	t_lhash			*new;

	tmp = *begin_lhash;
	if ((new = (t_lhash *)malloc(sizeof(t_lhash))) == NULL)
		return (NULL);
	if ((new->path = ft_strjoin(path, "/")) == NULL)
		return (NULL);
	if ((new->name = ft_strdup(name)) == NULL)
		return (NULL);
	new->next = NULL;
	if (tmp == NULL)
		return (new);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (*begin_lhash);
}

static int			get_files_hash(char **paths, t_hash *hash[])
{
	struct dirent	*files;
	DIR				*dir;
	int				i;
	int				val;

	i = 0;
	while (paths[i] != NULL)
	{
		if ((dir = opendir(paths[i])) == NULL)
			return (int_error(EOPEN));
		while ((files = readdir(dir)) != NULL)
		{
			if (files->d_name[0] == '.')
				continue ;
			val = hashage(files->d_name);
			hash[val]->lhash =
				add_lhash(&(hash[val]->lhash), files->d_name, paths[i]);
		}
		closedir(dir);
		i++;
	}
	return (0);
}

static int			init_hash(char ***paths, int *nb_bin)
{
	t_hash			**hash;

	if (!get_env_val("PATH") || ft_strcmp(get_env_val("PATH"), "") == 0)
		return (-1);
	if ((*paths = ft_strsplit(get_env_val("PATH"), ':')) == NULL ||
		g_env == NULL)
	{
		g_error = EALLOC;
		return (-1);
	}
	if ((*nb_bin = count_bin(*paths)) == -1)
		return (-1);
	hash = g_memory(S_HASH, sizeof(t_hash *) * *nb_bin + 1);
	if (hash == NULL)
	{
		g_error = EALLOC;
		return (-1);
	}
	return (0);
}

int					error_hashtab(void)
{
	free_brain(S_HASH);
	g_memory(S_HASH, -1);
	if (g_error == EALLOC)
		return (-1);
	g_error = NULL;
	return (0);
}

int					create_hashtab(void)
{
	int				i;
	int				nb_bin;
	t_hash			**hash;
	char			**paths;

	paths = NULL;
	nb_bin = 0;
	if (init_hash(&paths, &nb_bin) == -1)
		return (error_hashtab());
	i = 0;
	hash = g_memory(S_HASH, nb_bin);
	while (i < nb_bin)
	{
		if ((hash[i] = (t_hash *)ft_memalloc(sizeof(t_hash))) == NULL)
		{
			g_error = EALLOC;
			return (-1);
		}
		hash[i]->lhash = NULL;
		++i;
	}
	hash[i] = NULL;
	get_files_hash(paths, hash);
	ft_freetab(paths);
	return (0);
}
