/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 17:52:42 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/08 15:33:30 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

int				valid_char_funct(char c)
{
	if (c == '(')
		return (1);
	if (c == ')')
		return (1);
	if (ft_isalnum(c))
		return (1);
	return (0);
}

int				valid_char_var(char c)
{
	if (c == '=')
		return (1);
	if (c == '_')
		return (1);
	if (ft_isalnum(c))
		return (1);
	return (0);
}
