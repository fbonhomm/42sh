/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_one_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:31:56 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/14 18:48:50 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

char			*ft_str_one_space(char *str)
{
	char		**tmp;
	char		*str1;

	tmp = ft_split_mult(2, str, ' ', '\t');
	str1 = ft_tab_to_str(tmp, ' ');
	ft_free_array(&tmp);
	return (str1);
}
