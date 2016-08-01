/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:36:29 by ksoulard          #+#    #+#             */
/*   Updated: 2015/11/27 19:02:25 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d_str;

	d_str = (unsigned char *)dst;
	if (!dst || !src)
		return (dst);
	while (n--)
		*d_str++ = *(unsigned char *)src++;
	return (dst);
}
