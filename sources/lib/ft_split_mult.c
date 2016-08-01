/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/13 16:25:08 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 19:09:24 by flo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbtab(char const *str, char *c)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	nb = 1;
	while (str[i])
	{
		while (c[j])
		{
			if (str[i] == c[j])
			{
				nb++;
				i = ft_search_false(str, c, i);
				j = 0;
			}
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (nb);
}

char		**ft_tab(char **tabl, char const *str, char *c)
{
	int		i;
	int		k;
	int		nb;
	int		index;

	k = 0;
	index = 0;
	i = 0;
	while (str[i])
	{
		i = ft_search_false(str, c, i);
		nb = ft_search_true(str, c, i);
		if (nb != 0)
		{
			tabl[index] = (char*)malloc(sizeof(char) * (nb + 1));
			while (str[i] && k < nb)
				tabl[index][k++] = str[i++];
			tabl[index][k] = '\0';
			k = 0;
			index++;
		}
	}
	tabl[index] = NULL;
	return (tabl);
}

char		**ft_split_(char **tabl, char const *str, char *c, int i)
{
	tabl = (char**)malloc(sizeof(char*) * (i + 1));
	ft_tab(tabl, str, c);
	return (tabl);
}

char		**ft_none_chara(char **tabl, char const *str)
{
	tabl = (char**)malloc(sizeof(char*) * (2));
	tabl[0] = ft_strdup(str);
	tabl[1] = NULL;
	return (tabl);
}

char		**ft_split_mult(int nb, char const *str, ...)
{
	char	**tabl;
	char	*c;
	int		i;
	va_list ap;

	if (!str)
		return (NULL);
	tabl = NULL;
	i = 0;
	va_start(ap, str);
	c = (char*)malloc(sizeof(char) * (nb + 1));
	while (i < nb)
		c[i++] = va_arg(ap, int);
	c[i] = '\0';
	va_end(ap);
	if ((i = ft_nbtab(str, c)) == 1)
	{
		tabl = ft_none_chara(tabl, str);
		return (tabl);
	}
	tabl = ft_split_(tabl, str, c, i);
	ft_free(&c);
	return (tabl);
}
