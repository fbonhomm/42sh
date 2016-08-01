/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriot <eduriot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:33:31 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/15 10:21:04 by eduriot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

t_lextab			*new_elem(char **str)
{
	t_lextab		*tmp;

	tmp = (t_lextab *)malloc(sizeof(t_lextab));
	if (tmp == NULL)
		return (NULL);
	tmp->word = *str;
	tmp->next = NULL;
	tmp->prev = NULL;
	tmp->separator = 0;
	return (tmp);
}

void				add_lex(t_lextab **lex, t_lextab **begin, char **word)
{
	if (*word == NULL)
		return ;
	if (*lex == NULL)
	{
		*lex = new_elem(word);
		*begin = *lex;
	}
	else
	{
		(*lex)->next = new_elem(word);
		(*lex)->next->prev = *lex;
		*lex = (*lex)->next;
	}
}

void				add_list_lex(t_lextab **lex, t_lextab **begin, char *word)
{
	int				i;
	int				j;
	char			*s;

	i = 0;
	s = NULL;
	if (word == NULL)
		return ;
	while (word[i])
	{
		while (word[i] && is_blank(word[i]))
			++i;
		j = 0;
		while (word[i] && !is_blank(word[i]))
		{
			++j;
			++i;
		}
		s = ft_strsub(word, i - j, j);
		add_lex(lex, begin, &s);
		(*lex)->separator = ' ';
		(*lex)->no_parse = 1;
		++i;
	}
	ft_strdel(&word);
}

int					lexer2(char **word, char *act, t_lextab **begin)
{
	char			*new;
	t_parser		*parser;

	parser = g_memory(S_PARSER, 0);
	if (**word == '\"')
		new = format_doublequote(*word, 1);
	else if (**word == '\'')
		new = format_simplequote(*word);
	else if (**word == '`')
	{
		new = format_backquote(*word);
		add_list_lex(&parser->lex, begin, new);
	}
	else
		new = format_doublequote(*word, 0);
	if ((**word != '`' || parser->lex == NULL) && new != NULL)
	{
		add_lex(&parser->lex, begin, &new);
		parser->lex->no_parse = **word == '\\' ? 1 : 0;
		parser->lex->token = is_operator(**word) ? OPERATOR : -1;
		parser->lex->separator = is_blank(*act) ? *act : 0;
	}
	ft_strdel(word);
	return (0);
}

int					lexer(char *str)
{
	int				i;
	t_parser		*parser;
	t_lextab		*begin;
	char			*word;

	i = 0;
	word = NULL;
	begin = NULL;
	parser = g_memory(S_PARSER, 0);
	while (str[i] != '\0')
	{
		while (str[i] && is_blank(str[i]))
			++i;
		if (str[i] == '\0')
			break ;
		i += get_word(&str[i], &word, i);
		if (word != NULL)
			lexer2(&word, &str[i], &begin);
	}
	parser->lex = begin;
	return (0);
}
