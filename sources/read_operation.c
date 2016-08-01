/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 14:39:26 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/02 11:57:29 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static int		verif_backslash(t_line *line)
{
	int			backslash;

	if (line == NULL || (line->prev && line->prev->ch != '\\'))
		return (0);
	backslash = 0;
	while (line->prev && line->prev->ch == '\\')
		line = line->prev;
	while (line != NULL && line->ch == '\\')
	{
		++backslash;
		line = line->next;
	}
	return (backslash % 2);
}

static int		get_quote_value(int quote)
{
	static char	*tquote = "''\"\"``{}()[]";
	char		*p;

	p = ft_strchr(tquote, quote);
	return (p == NULL ? 0 : 1 << ((p - tquote) / 2));
}

static int		quote_modifier(t_line *line, int quote)
{
	int			new_quote;

	new_quote = get_quote_value(line->ch);
	if (verif_backslash(line) != 0)
		return (quote);
	if (read_open_quote(line->ch) && (quote == 0
	|| (quote == DQUOTE && new_quote == BQUOTE)))
		quote |= new_quote;
	else if (read_close_quote(line->ch) && quote != 0
	&& (quote == new_quote || (new_quote == BQUOTE && quote & BQUOTE)))
		quote ^= new_quote;
	return (quote);
}

int				get_quote(t_cmline *cm_tmp, t_line *line_tmp, t_win *term)
{
	while (cm_tmp)
	{
		line_tmp = cm_tmp->line;
		while (line_tmp)
		{
			if (read_is_quote(line_tmp->ch))
				term->quote = quote_modifier(line_tmp, term->quote);
			line_tmp = line_tmp->next;
		}
		cm_tmp = cm_tmp->next;
	}
	return (term->quote ? RELAUNCH : ENDOF);
}

int				end_or_relaunch(t_win *term, int key)
{
	t_cmline	*cm_tmp;
	t_line		*line_tmp;

	UNUSED(key);
	term->quote = 0;
	cm_tmp = term->all_act->cm;
	line_tmp = cm_tmp->line;
	if (cm_tmp)
		while (cm_tmp->prev)
		{
			line_tmp = cm_tmp->line;
			if (line_tmp)
				while (line_tmp->prev)
					line_tmp = line_tmp->prev;
			cm_tmp = cm_tmp->prev;
		}
	return (get_quote(cm_tmp, line_tmp, term));
}
