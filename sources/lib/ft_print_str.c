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

#include "libft.h"

void		ft_print_str(int nb, ...)
{
	va_list ap;
	int		i;

	va_start(ap, nb);
	i = 0;
	while (i++ < nb)
		ft_putstr(va_arg(ap, char*));
	va_end(ap);
}
