/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_mult.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 23:57:55 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 23:57:57 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

char			*cast_tabl(char **tabl)
{
	char		*str;
	int			len;
	int			i;
	int			x;
	int			y;

	i = 0;
	x = 0;
	y = 0;
	len = 0;
	while (tabl[i])
		len = len + ft_strlen(tabl[i++]);
	str = (char*)malloc(sizeof(char) * (len + 2));
	i = 0;
	while (tabl[y])
	{
		while (tabl[y][x])
			str[i++] = tabl[y][x++];
		x = 0;
		y++;
	}
	str[i] = '\0';
	return (str);
}

char			*ft_strjoin_mult(int nb, ...)
{
	va_list		ap;
	int			i;
	char		**tabl;
	char		*str;

	va_start(ap, nb);
	tabl = (char**)malloc(sizeof(char*) * (nb + 1));
	i = 0;
	while (i < nb)
	{
		tabl[i] = ft_strdup(va_arg(ap, char*));
		i++;
	}
	tabl[i] = NULL;
	va_end(ap);
	str = cast_tabl(tabl);
	ft_free_array(&tabl);
	return (str);
}
