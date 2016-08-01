/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:40:34 by ksoulard          #+#    #+#             */
/*   Updated: 2015/11/27 19:06:54 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *d_str;

	d_str = s1;
	d_str += ft_strlen(d_str);
	while (n-- && *s2)
		*d_str++ = *s2++;
	*d_str = '\0';
	return (s1);
}
