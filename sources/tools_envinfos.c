/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_envinfos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:35:36 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/04 19:20:21 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static char		*g_name[5] = {
	"PWD",
	"OLDPWD",
	"SHLVL",
};

static int	apply_modif(char *s)
{
	if (expand_env(s) == -1)
		return (-1);
	return (0);
}

int			get_newenv(char **env)
{
	char	*s;
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
			if ((s = g_get_env(g_name[i])) == NULL)
				return (int_error(EALLOC));
			if (apply_modif(s) == -1)
			{
				ft_strdel(&s);
				return (-1);
			}
			ft_strdel(&s);
		}
		i++;
	}
	return (0);
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
		if (ft_strncmp(g_env[i], var, s - g_env[i]) == 0
			&& ft_strlen(var) == (size_t)(s - g_env[i]))
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
		if (ft_strncmp(g_env[i], var, s - g_env[i]) == 0
			&& ft_strlen(var) == (size_t)(s - g_env[i]))
			break ;
		i++;
	}
	return (g_env[i] == NULL ? NULL : s + 1);
}
