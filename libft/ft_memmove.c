/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:36:44 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/14 14:28:32 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *d_str;

	d_str = (unsigned char *)dst;
	if ((unsigned char *)src <= d_str)
	{
		src += n - 1;
		d_str += n - 1;
		while (n--)
			*d_str-- = *(unsigned char *)src--;
	}
	else
		ft_memcpy(dst, src, n);
	return (dst);
}
