/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:36:10 by ksoulard          #+#    #+#             */
/*   Updated: 2015/11/27 19:00:05 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d_str;

	d_str = (unsigned char *)dst;
	if (!dst || !src)
		return (NULL);
	while (n--)
	{
		if (*(unsigned char*)src == (unsigned char)c)
		{
			*d_str = c;
			return (++d_str);
		}
		*d_str++ = *(unsigned char *)src++;
	}
	return (NULL);
}
