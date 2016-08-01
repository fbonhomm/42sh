/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_envinfos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:35:36 by ksoulard          #+#    #+#             */
/*   Updated: 2016/07/25 18:10:52 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static char		*g_name[5] = {
	"PWD",
	"OLDPWD",
	"SHLVL",
};

static int	apply_modif(char *(f)(char *), int i, char *s)
{
	char	*tmp;

	if (s == NULL)
	{
		if (expand_env((*f)(g_name[i])) == -1)
			return (-1);
		return (0);
	}
	tmp = ft_strchr((*f)(g_name[i]), '=');
	if (tmp == NULL)
		return (0);
	if (modif_env(g_name[i], tmp + 1) == -1)
		return (-1);
	if (create_hashtab() == -1)
	{
		if (g_error == EALLOC)
			return (-1);
		g_error = NULL;
	}
	return (0);
}

int			get_newenv(char **env)
{
	char	*s;
	char	*(*f)(char *);
	int		i;

	i = 0;
	if (g_env == NULL)
		g_env = ft_cp_tab(env, g_env);
	if (g_env == NULL)
		return (int_error(EALLOC));
	while (g_name[i] && g_env)
	{
		if ((s = get_env_val(g_name[i])) == NULL || ft_strcmp(s, "") == 0)
		{
			if ((f = g_get_env(g_name[i])) == NULL)
				break ;
			if (apply_modif(f, i, s) == -1)
				return (-1);
		}
		i++;
	}
	return (f == NULL && s == NULL ? -1 : 0);
}

char		*get_env_line(char *var)
{
	int		i;
	char	*s;

	i = 0;
	if (g_env == NULL)
		return (NULL);
	while (g_env[i] != NULL)
	{
		s = ft_strchr(g_env[i], '=');
		if (ft_strncmp(g_env[i], var, s - g_env[i]) == 0)
			break ;
		i++;
	}
	return (g_env[i] == NULL ? NULL : g_env[i]);
}

char		*get_env_val(char *var)
{
	int		i;
	char	*s;

	i = 0;
	if (g_env == NULL)
		return (NULL);
	while (g_env[i] != NULL)
	{
		s = ft_strchr(g_env[i], '=');
		if (ft_strncmp(g_env[i], var, s - g_env[i]) == 0)
			break ;
		i++;
	}
	return (g_env[i] == NULL ? NULL : s + 1);
}
