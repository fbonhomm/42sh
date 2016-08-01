/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:15:44 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/19 16:52:17 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** - Fonction qui renvoie le nombre de mots separer par les delimiteurs -
**   PROTOTYPE: int ft_parameter(int nbr(nbr de delimiteur), char *str(ligne), ...(delimiteur))
*/

int				ft_match(char const *str, int *i,  char *c)
{
	int			index;
	int			nbr;

	index = 0;
	nbr = 0;
	while (c[index] && str[*i])
	{
		if (str[*i] == c[index])
		{
			*i += 1;
			index = 0;
			nbr = 1;
		}
		else
			index++;
	}
	return (nbr);
}

int				ft_count_para(char const *str, char *c)
{
	int			i;
	int			nbr;

	nbr = 1;
	i = 0;
	while (str[i])
	{
		if (ft_match(str, &i, c))
			nbr++;
		else
			i++;
	}
	return (nbr);
}


int				ft_parameter(int nb, char const *str, ...)
{
	char		*c;
	int			i;
	va_list		ap;

	if (!str)
		return (0);
	i = 0;
	va_start(ap, str);
	c = (char*)malloc(sizeof(char) * (nb + 1));
	while (i < nb)
		c[i++] = va_arg(ap, int);
	c[i] = '\0';
	va_end(ap);
	i = ft_count_para(str, c);
	ft_free(&c);
	return (i);
}
