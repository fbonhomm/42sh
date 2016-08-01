/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:41:35 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/02 11:35:40 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	nb_str(char const *str, char c)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str != '\0')
	{
		while (*str == c)
			str++;
		if (*str != c && *str != '\0')
			i++;
		str++;
	}
	return (i);
}

static int	len_str(const char *str, char c)
{
	int		i;

	i = 0;
	while (*str != c && *str++ != '\0')
		i++;
	return (i);
}

static char	**cpy_str(const	char *str, char c, char **tab)
{
	int		i;
	int		nb;

	i = 0;
	while (1)
	{
		while (*str == c)
			str++;
		if (*str == '\0')
		{
			tab[i] = NULL;
			return (tab);
		}
		nb = len_str(str, c);
		tab[i] = (char *)ft_memalloc(sizeof(char) * nb + 1);
		if (tab[i] == NULL)
			return (NULL);
		tab[i] = ft_strncpy(tab[i], str, nb);
		str += nb;
		i++;
	}
	return (tab);
}

char		**ft_strsplit(const char *str, char c)
{
	char	**tab;

	tab = (char **)malloc(sizeof(char *) * nb_str(str, c) + 1);
	if (str == NULL || tab == NULL)
	{
		free(tab);
		return (NULL);
	}
	tab = cpy_str(str, c, tab);
	return (tab);
}
