/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cp_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 09:27:51 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/02 14:45:47 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_cp_tab(char **src, char **dst)
{
	int		i;

	i = 0;
	if (src == NULL)
		return (NULL);
	while (src[i])
		++i;
	if ((dst = (char **)malloc(sizeof(char *) * i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		if ((dst[i] = ft_strdup(src[i])) == NULL)
		{
			ft_freetab(dst);
			return (NULL);
		}
		++i;
	}
	dst[i] = NULL;
	return (dst);
}
