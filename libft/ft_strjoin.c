/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: killian <killian@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:40:01 by ksoulard          #+#    #+#             */
/*   Updated: 2016/02/20 12:47:39 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p_str;

	if (!s1 || !s2)
		return (NULL);
	p_str = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p_str)
		return (NULL);
	return (ft_strcat(ft_strcpy(p_str, s1), s2));
}
