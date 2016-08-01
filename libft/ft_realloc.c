/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:38:16 by ksoulard          #+#    #+#             */
/*   Updated: 2015/12/02 10:52:49 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new;

	if (ptr == NULL || size <= 0)
		return (NULL);
	new = malloc(size);
	ft_memcpy(new, ptr, ft_strlen(ptr) + 1);
	free(ptr);
	return (new ? new : NULL);
}
