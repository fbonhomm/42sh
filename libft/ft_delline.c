/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 09:44:47 by ksoulard          #+#    #+#             */
/*   Updated: 2016/03/14 08:41:04 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_delline(char **tb, char *line)
{
	int		i;
	int		j;
	char	**new;

	j = 0;
	i = ft_tblen(tb);
	if ((new = (char **)malloc(sizeof(char *) * i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (tb[i])
	{
		if (ft_strcmp(tb[i], line) != 0)
		{
			if ((new[j] = ft_strdup(tb[i])) == NULL)
			{
				ft_freetab(new);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	new[j] = NULL;
	return (new);
}
