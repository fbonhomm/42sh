/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lexer2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriot <eduriot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:33:35 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/15 10:32:51 by eduriot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int				check_backslash(char *c, int pos)
{
	int			backslash;
	int			i;

	i = -1;
	if (pos == 0)
		return (1);
	if (c[-1] != '\\')
		return (1);
	backslash = 0;
	while (pos > -1 && c[i] == '\\')
	{
		++backslash;
		--pos;
		--i;
	}
	return (!backslash % 2);
}

int				get_simple_word(char *line, int i, int pos)
{
	while (line[i])
	{
		if (is_blank(line[i]) || ((is_quote(line[i]) || is_operator(line[i]))
			&& check_backslash(&line[i], i + pos)))
			break ;
		++i;
	}
	return (i);
}

int				get_quote_word(char *line, int i, int pos)
{
	char		c;
	int			inbquote;

	c = line[i - 1];
	inbquote = 0;
	while (line[i])
	{
		if (is_quote(line[i]) && line[i] == c && check_backslash(&line[i], pos
			+ i) && inbquote == 0)
			break ;
		if (is_quote(line[i]) && line[i] == '`' && c == '\"')
			inbquote = !inbquote;
		++i;
	}
	if (line[i])
		++i;
	else if (c == '\'')
		return (-1);
	else if (c == '\"')
		return (-2);
	return (i);
}

int				get_operator_word(char *line, int i, int pos)
{
	while (line[i])
	{
		if (!is_operator(line[i + 1]) && check_backslash(&line[i], pos + i))
			break ;
		++i;
	}
	if (line[i])
		++i;
	return (i);
}

int				get_word(char *line, char **new_word, int pos)
{
	int			ret;

	if (is_quote(*line) && check_backslash(line, pos))
		ret = get_quote_word(line, 1, pos);
	else if (is_operator(*line) && check_backslash(line, pos))
		ret = get_operator_word(line, 0, pos);
	else
		ret = get_simple_word(line, 1, pos);
	if (ret == -1)
	{
		ft_putendl_fd(PEICS2, STDERR_FILENO);
		free_brain(S_PARSER);
		exit(EXIT_FAILURE);
	}
	else if (ret == -2)
	{
		ft_putendl_fd(PEICS, STDERR_FILENO);
		free_brain(S_PARSER);
		exit(EXIT_FAILURE);
	}
	if (ret != 0)
		*new_word = ft_strndup(line, ret);
	return (ret);
}
