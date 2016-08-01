/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:41:55 by ksoulard          #+#    #+#             */
/*   Updated: 2016/02/06 07:39:34 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p_str;

	if (s == NULL || ft_strcmp(s, "") == 0)
		return (NULL);
	p_str = (char *)ft_memalloc(sizeof(char) * len + 1);
	if (p_str == NULL)
		return (NULL);
	return (ft_strncpy(p_str, s += start, len));
}
