/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 23:46:36 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/03/02 23:46:40 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_free_and_return(char *s3, int i)
{
	ft_free(&s3);
	return (i);
}

int			ft_sort_str(char *s1, char *s2)
{
	int		i;
	char	*s3;

	i = 0;
	if ((ft_strlen(s1)) > (ft_strlen(s2)))
		s3 = ft_strdup(s2);
	else
		s3 = ft_strdup(s1);
	while (s3[i])
	{
		if (s1[i] > s2[i])
			return (ft_free_and_return(s3, 1));
		if (s1[i] < s2[i])
			return (ft_free_and_return(s3, 2));
		i++;
	}
	if ((ft_strlen(s1)) > (ft_strlen(s2)))
		return (ft_free_and_return(s3, 1));
	return (ft_free_and_return(s3, 2));
}
