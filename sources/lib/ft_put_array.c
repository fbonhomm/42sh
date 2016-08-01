/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/12 14:04:41 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 17:06:41 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_array(char **tabl, char *c)
{
	int	i;

	i = 0;
	if (!tabl || !c)
		return ;
	while (tabl[i])
	{
		ft_putstr(tabl[i]);
		ft_putstr(c);
		i++;
	}
}
