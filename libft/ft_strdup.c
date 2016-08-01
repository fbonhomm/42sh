/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:39:15 by ksoulard          #+#    #+#             */
/*   Updated: 2016/02/15 09:25:49 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(char const *s)
{
	char	*s2;

	if (s == NULL)
		return (NULL);
	s2 = (char *)malloc(sizeof(*s) * ft_strlen(s) + 1);
	return (s2 ? ft_strcpy(s2, s) : 0);
}
