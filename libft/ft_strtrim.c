/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:42:08 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/08 16:07:47 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int	i;
	int	len;

	i = -1;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s) - 1;
	if (ft_strcmp(s, "") == 0)
		return (ft_strnew(1));
	while (s[len] == ' ' || s[len] == ',' || s[len] == '\n' || s[len] == '\t')
		len--;
	while (s[++i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		len--;
	if (len++ < 0)
		len = 0;
	return (ft_strsub(s, i, len));
}
