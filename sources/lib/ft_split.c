/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/29 16:41:35 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/09/29 16:41:38 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbtab(char const *s, char c, char d)
{
	int i;
	int nbr;

	i = 0;
	while ((s[i] == c && s[i]) || (s[i] == d && s[i]))
		i++;
	nbr = 0;
	while (s[i])
	{
		while (s[i] && s[i] != c && s[i] != d)
			i++;
		nbr++;
		while ((s[i] && s[i] == c) || (s[i] && s[i] == d))
			i++;
	}
	return (nbr);
}

char			**ft_split(char const *s, char c, char d)
{
	int		index;
	int		j;
	char	**str;
	int		k;

	if ((!s) || (str = malloc(sizeof(str) * (ft_nbtab(s, c, d) + 1))) == NULL)
		return (NULL);
	index = 0;
	j = 0;
	while (s[j] && (index < ft_nbtab(s, c, d)))
	{
		while ((s[j] == c) || (s[j] == d))
			j++;
		str[index] = ft_strnew(ft_strlen(s));
		if (str[index] == NULL)
			return (NULL);
		k = 0;
		while (s[j] != c && s[j] && s[j] != d)
			str[index][k++] = s[j++];
		str[index][k] = '\0';
		index++;
	}
	str[index] = NULL;
	return (str);
}
