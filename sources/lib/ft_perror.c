/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 15:56:16 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/05/25 17:22:49 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "inc_error.h"

void				ft_perror(char *s)
{
	char			*str;

	str = ft_strjoin_mult(4, s, ": ", errlst[errno], "\n");
	write(STDERR_FILENO, str, ft_strlen(str));
	free(str);
}
