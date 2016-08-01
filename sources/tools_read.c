/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:36:15 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/02 11:57:14 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

int				read_is_quote(int x)
{
	return ((x == '\"' || x == '\'' || x == '`' || x == '{' || x == '}'
		|| x == '[' || x == '[' || x == ']' || x == '(' || x == ')'));
}

int				read_open_quote(int x)
{
	return ((x == '\'' || x == '\"' || x == '`' || x == '{' || x == '['
		|| x == '('));
}

int				read_close_quote(int x)
{
	return ((x == '\'' || x == '\"' || x == '`' || x == '}' || x == ']'
		|| x == ')'));
}

int				test_caps(void)
{
	char		*tb[7];
	int			i;

	i = 0;
	tb[0] = "cd";
	tb[1] = "le";
	tb[2] = "up";
	tb[3] = "do";
	tb[4] = "nd";
	tb[5] = "vi";
	tb[6] = "ve";
	while (i < 7)
	{
		if (tgetstr(tb[i], NULL) == NULL)
		{
			g_error = ETERMERR;
			return (-1);
		}
		++i;
	}
	return (0);
}

int				nb_ch_after_cur(t_cmline *cm)
{
	int			nb;

	nb = cm->ch_after_cur;
	cm = cm->next;
	while (cm != NULL)
	{
		nb += cm->line_len;
		cm = cm->next;
	}
	return (nb);
}
