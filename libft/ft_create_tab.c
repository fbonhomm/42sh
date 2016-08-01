/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 09:04:07 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/08 13:47:53 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_create_tab(int nb)
{
	char	**str;
	int		i;

	str = NULL;
	i = 0;
	if (nb <= 0)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * (nb + 1))))
		return (NULL);
	str[nb] = NULL;
	while (i < nb)
	{
		if (!(str[i] = (char *)malloc(sizeof(char) * (nb + 1))))
		{
			while (i > 0)
				free(str[i--]);
			free(str);
			str = NULL;
			return (NULL);
		}
		str[i][nb] = '\0';
		i++;
	}
	return (str);
}
