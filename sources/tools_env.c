/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:35:40 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:35:40 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

char		*strcatstr(char *s1, char *s2, char *op)
{
	char	*tmp;
	char	*str;

	str = NULL;
	if (s1 == NULL)
		return (NULL);
	if ((tmp = ft_strjoin(s1, op)) == NULL)
		return (NULL);
	if (s2 == NULL)
		return (tmp);
	str = ft_strjoin(tmp, s2);
	ft_strdel(&tmp);
	return (str);
}

int			modif_env(char *var, char *value)
{
	char	*s;
	int		i;
	char	*tmp;

	i = 0;
	if (g_env == NULL || value == NULL)
		return (-1);
	while (g_env[i] != NULL)
	{
		s = ft_strchr(g_env[i], '=');
		if (ft_strncmp(g_env[i], var, s - g_env[i]) == 0)
			break ;
		i++;
	}
	if (g_env[i] != NULL)
	{
		tmp = g_env[i];
		*s = '\0';
		g_env[i] = strcatstr(g_env[i], value, "=");
		ft_strdel(&tmp);
	}
	if (g_env[i] == NULL)
		g_error = EALLOC;
	return (g_env[i] ? 0 : -1);
}

int			expand_env(char *new_line)
{
	int		i;
	char	**new_env;

	i = 0;
	if (g_env == NULL || new_line == NULL)
		return (-1);
	while (g_env[i])
		i++;
	if ((new_env = (char **)malloc(sizeof(*new_env) * (i + 2))) == NULL)
		return (-1);
	i = -1;
	while (g_env[++i])
		if ((new_env[i] = ft_strdup(g_env[i])) == NULL)
			break ;
	if (g_env[i] != NULL)
	{
		ft_freetab(g_env);
		ft_freetab(new_env);
		return (-1);
	}
	ft_freetab(g_env);
	new_env[i] = ft_strdup(new_line);
	new_env[++i] = NULL;
	g_env = new_env;
	return (0);
}
