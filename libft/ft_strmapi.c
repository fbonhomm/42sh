/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:40:26 by ksoulard          #+#    #+#             */
/*   Updated: 2015/11/27 19:06:48 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*p_str;

	i = 0;
	if (!s || !f || !(p_str = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		p_str[i] = f(i, (char)s[i]);
		i++;
	}
	p_str[i] = '\0';
	return (p_str);
}
