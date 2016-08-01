/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:39:37 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/07 17:48:19 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void			add_env(t_var **v, char **env)
{
	int			i;
	char		*key;
	char		*value;

	i = -1;
	key = NULL;
	value = NULL;
	while (env[++i])
	{
		split_var(env[i], &key, &value);
		add_node_var(v, key, value);
		ft_free(&key);
		ft_free(&value);
	}
}
