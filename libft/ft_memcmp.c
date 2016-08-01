/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:36:23 by ksoulard          #+#    #+#             */
/*   Updated: 2015/11/27 19:00:18 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *str1;

	str1 = (unsigned char *)s1;
	if (!s1 || !s2 || !n)
		return (0);
	while ((n > 0 && (*str1++ == *(unsigned char *)s2++)))
		n--;
	return (*--str1 - *(unsigned char *)--s2);
}
