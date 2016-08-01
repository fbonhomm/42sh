/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:41:28 by ksoulard          #+#    #+#             */
/*   Updated: 2015/11/27 19:08:05 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_str;

	s_str = NULL;
	while (1)
	{
		if (*s == (unsigned char)c)
			s_str = (char *)s;
		if (*s++ == '\0')
			return (s_str);
	}
}
