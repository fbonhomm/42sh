/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strepur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:31:56 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/14 18:53:52 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int				valid(char c, char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char			*ft_strepur(int nb, char *str, ...)
{
	va_list		ap;
	int			i[2];
	char		*chaine;
	char		*str1;

	va_start(ap, str);
	i[0] = 0;
	chaine = (char*)malloc(sizeof(char) * (nb + 1));
	str1 = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (i[0] < nb)
		chaine[i[0]++] = va_arg(ap, int);
	chaine[i[0]] = '\0';
	va_end(ap);
	i[0] = 0;
	i[1] = 0;
	while (str[i[0]])
	{
		if (valid(str[i[0]], chaine))
			str1[i[1]++] = str[i[0]++];
		else
			i[0]++;
	}
	str1[i[1]] = '\0';
	ft_free(&chaine);
	return (str1);
}
