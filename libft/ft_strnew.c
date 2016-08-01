/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:14:06 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/08 16:02:50 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t n)
{
	char	*new;

	new = (char *)malloc(sizeof(*new) * (n + 1));
	return (new ? ft_memset(new, 0, n + 1) : NULL);
}
