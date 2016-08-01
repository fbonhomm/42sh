/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 16:16:13 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/14 18:09:27 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void			split_var(const char *str, char **k, char **v)
{
	int			i;
	int			j;
	char		*key;
	char		*value;

	i = 0;
	j = 0;
	key = (char*)malloc(sizeof(char) * ft_strlen(str));
	value = (char*)malloc(sizeof(char) * ft_strlen(str));
	while (str[i] && str[i] != '=')
	{
		key[i] = str[i];
		i++;
	}
	key[i++] = '\0';
	while (str[i])
		value[j++] = str[i++];
	value[j] = '\0';
	*k = key;
	*v = value;
}
