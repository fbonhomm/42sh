/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:58:16 by ksoulard          #+#    #+#             */
/*   Updated: 2016/03/09 19:50:28 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_expand_tab(char **str, char *new)
{
	int		i;
	char	**dst;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	if ((dst = (char **)malloc(sizeof(char *) * (i + 2))) == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if ((dst[i] = ft_strdup(str[i])) == NULL)
		{
			ft_freetab(dst);
			return (NULL);
		}
		i++;
	}
	if ((dst[i] = ft_strdup(new)) == NULL)
		return (NULL);
	dst[++i] = NULL;
	return (dst);
}
