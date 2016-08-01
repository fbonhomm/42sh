/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_tilde.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:36:19 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/06 14:06:24 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static int			replace_path(char *env, char **path)
{
	char			*tmp;
	char			*tmp2;

	if ((tmp2 = ft_strjoin(env, (*path) + 1)) == NULL)
		return (int_error(EALLOC));
	free(*path);
	*path = tmp2;
	ft_strdel(&tmp);
	return (0);
}

int					convert_tilde(char **path)
{
	char			*home;

	if (!(*path))
		return (0);
	if (*path[0] != '~')
		return (0);
	if ((*path)[1] && (*path)[1] != '/')
		return (0);
	home = get_env_val("HOME");
	if (home == NULL)
		return (int_error(ENVH));
	if (parser_path(home, 'd', S_IXUSR) == -1)
		return (-1);
	return (replace_path(home, path));
}
