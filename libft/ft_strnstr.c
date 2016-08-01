/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:41:03 by ksoulard          #+#    #+#             */
/*   Updated: 2016/02/15 07:41:06 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*p_s1;
	size_t	i;

	p_s1 = (char *)s1;
	if (!s2 || !s1)
		return (NULL);
	i = ft_strlen(s2);
	if (!ft_strcmp(s2, ""))
		return (p_s1);
	while (n-- >= i && *p_s1)
	{
		if (*p_s1 == *s2)
		{
			if (ft_strncmp(p_s1, s2, i) == 0)
				return (p_s1);
		}
		p_s1++;
	}
	return (NULL);
}
