/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conform_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 17:52:42 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 19:32:38 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int				ft_exit(char *str)
{
	ft_free(&str);
	return (0);
}

int				conform_set_var(char *str)
{
	int			i;
	int			booleen;

	i = 0;
	booleen = 0;
	if ((!str) || ((!ft_isalpha(str[0])) && str[0] != '_'))
		return (0);
	while (str[i])
	{
		if (!valid_char_var(str[i]))
			return (0);
		if (str[i] == '=')
			booleen = 1;
		i++;
	}
	return (booleen);
}

int				conform_set_funct(char *s)
{
	int			i;
	int			len;
	char		*str;

	i = 0;
	str = ft_strepur(2, s, ' ', '\t');
	if ((!str) || ((!ft_isalpha(str[0])) && str[0] != '_'))
		return (ft_exit(str));
	len = ft_strlen(str);
	if ((search_parenth(str) != 2) || (str[len - 2] != '(') ||
			(str[len - 1] != ')'))
		return (ft_exit(str));
	while (str[i])
	{
		if (!valid_char_funct(str[i]))
			return (ft_exit(str));
		i++;
	}
	ft_free(&str);
	return (1);
}
