/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_doublequote_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:33:13 by ksoulard          #+#    #+#             */
/*   Updated: 2016/07/26 12:41:31 by eduriot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

static void			set_var(int *i, int *test)
{
	*i += 1;
	*test = 0;
}

static void			clean_string(int *type, char **str, char **tmp)
{
	*type = 1;
	ft_strdel(str);
	*str = *tmp;
}

char				*handle_comp(char *str, int *type, int test)
{
	char			*tmp;
	int				i;
	int				j;

	j = ft_strlen(str);
	i = 0;
	while (i < j)
	{
		if (str[i] == '\\')
			tmp = handle_backslash(str, &i);
		else if (str[i] == '$' && str[i + 1])
			tmp = handle_dollar(str, &i);
		else if (str[i] == '`')
		{
			if ((tmp = handle_backquote(str, &i)) == NULL)
				return (NULL);
		}
		else
			set_var(&i, &test);
		if (test)
		{
			ft_putendl(tmp);
			clean_string(type, &str, &tmp);
		}
		j = ft_strlen(str);
	}
	return (str);
}
