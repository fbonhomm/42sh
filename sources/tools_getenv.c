/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_getenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:35:58 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/03 22:53:47 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

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

char		*g_get_env(char *var)
{
	if (ft_strcmp(var, "SHLVL") == 0)
		return (get_shlvl(NULL));
	else if (ft_strcmp(var, "PWD") == 0)
		return (get_pwd(NULL));
	else if (ft_strcmp(var, "OLDPWD") == 0)
		return (get_oldpwd(NULL));
	return (NULL);
}
