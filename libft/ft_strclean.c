/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 16:01:14 by ksoulard          #+#    #+#             */
/*   Updated: 2016/03/16 14:44:46 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_countchar(char *s)
{
	int			i;

	i = 0;
	while (*s)
	{
		if ((*s == ' ' || *s == '\t') && (*(s + 1) == ' ' || *(s + 1) == '\t'))
			i++;
		else if (*s == '"')
			i++;
		s++;
	}
	return (i);
}

static void		ft_cpchar(char *s, char **dst)
{
	int			i;

	i = 0;
	while (*s)
	{
		if ((*s == ' ' || *s == '\t') && (*(s + 1) == ' ' || *(s + 1) == '\t'))
			s++;
		else
		{
			if (*s == '\t')
				(*dst)[i++] = ' ';
			else if (*s == '"')
			{
				s++;
				continue ;
			}
			else
				(*dst)[i++] = *s;
			s++;
		}
	}
}

char			*ft_strclean(char *s)
{
	char		*p;
	char		*tmp;

	if (s == NULL)
		return (s);
	tmp = ft_strtrim(s);
	if ((p = ft_strnew(ft_strlen(tmp) - ft_countchar(tmp))) == NULL)
	{
		ft_strdel(&tmp);
		return (NULL);
	}
	ft_cpchar(tmp, &p);
	ft_strdel(&tmp);
	return (p);
}
