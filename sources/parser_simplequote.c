/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_simplequote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:33:55 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:33:56 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

char				*format_simplequote(char *str)
{
	int				j;
	int				i;
	int				len;
	char			*tmp;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	tmp = (char*)malloc(sizeof(char) * len);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, len);
	while (str[i])
	{
		if (str[i] == '\'')
			i++;
		else
		{
			tmp[j] = str[i];
			i++;
			j++;
		}
	}
	return (tmp);
}
