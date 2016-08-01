/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 10:16:34 by fbonhomm          #+#    #+#             */
/*   Updated: 2015/10/14 10:17:10 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

void			ft_print_str_endl(int nb, ...)
{
	va_list		ap;
	int			i;

	va_start(ap, nb);
	if (nb != 1)
	{
		i = 0;
		while (i++ < nb)
			ft_putstr_fd(va_arg(ap, char*), 2);
	}
	else
		ft_putstr_fd(va_arg(ap, char*), 2);
	va_end(ap);
}
