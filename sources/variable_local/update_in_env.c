/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_in_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 20:23:50 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 19:21:37 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include "set.h"

void			update_in_env(char *key, char *value)
{
	char		**tmp;
	int			i;
	int			ret;

	i = -1;
	while (g_env[++i])
	{
		if ((ret = ft_strncmp(key, g_env[i], (ft_strlen(key)))) == 0)
		{
			tmp = ft_strsplit(g_env[i], '=');
			ft_free(&tmp[1]);
			ft_free(&g_env[i]);
			tmp[1] = ft_strdup(value);
			g_env[i] = ft_tab_to_str(tmp, '=');
			ft_free_array(&tmp);
			break ;
		}
	}
}
