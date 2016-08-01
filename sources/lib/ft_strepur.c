/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strepur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:31:56 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 19:12:36 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	int			i;
	int			j;
	char		*chaine;
	char		*str1;

	va_start(ap, str);
	i = 0;
	chaine = (char*)malloc(sizeof(char) * (nb + 1));
	str1 = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (i < nb)
		chaine[i++] = va_arg(ap, int);
	chaine[i] = '\0';
	va_end(ap);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (valid(str[i], chaine))
			str1[j++] = str[i++];
		else
			i++;
	}
	str1[j] = '\0';
	ft_free(&chaine);
	return (str1);
}
