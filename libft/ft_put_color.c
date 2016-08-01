/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/15 09:41:56 by ksoulard          #+#    #+#             */
/*   Updated: 2016/01/15 09:45:46 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_put_color(char *name, char *color, int mode)
{
	ft_putstr(color);
	if (mode == 1)
		ft_putendl(name);
	else
		ft_putstr(name);
	ft_putstr("\033[0m");
}
