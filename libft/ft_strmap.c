/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:40:23 by ksoulard          #+#    #+#             */
/*   Updated: 2015/11/27 14:23:02 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*p_str;
	size_t	i;

	i = 0;
	if (!s || !f || !(p_str = ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	while (s[i])
	{
		p_str[i] = f((char)s[i]);
		i++;
	}
	return (p_str);
}
