/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_tilde.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:36:19 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/03 22:26:05 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

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
	if ((*path = ft_strjoin(home, (*path) + 1)) == NULL)
		return (int_error(EALLOC));
	return (0);
}
