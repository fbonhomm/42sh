/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tokenise.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:33:59 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/06 13:43:57 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static int		add_simple_token(t_lextab *prevlex, t_lextab *lex, t_lextab
				*nextlex)
{
	if (prevlex == NULL)
	{
		if (lex->next && lex->next->token == OPERATOR
			&& lex->next->subtok < PIPE && lex->separator == 0
			&& (ft_atoi(lex->word) != 0
			|| ft_strcmp(lex->word, "0") == 0))
			lex->token = IO_NUMBER;
		else
			lex->token = WORD;
	}
	else if (prevlex->subtok < PIPE && prevlex->token == OPERATOR
		&& lex->no_parse == 0)
		lex->token = IO_FILE;
	else if (nextlex && nextlex->subtok < PIPE && nextlex->token == OPERATOR
		&& lex->separator == 0 && (ft_atoi(lex->word) != 0
			|| ft_strcmp(lex->word, "0") == 0) && lex->no_parse == 0)
		lex->token = IO_NUMBER;
	else
		lex->token = WORD;
	return (0);
}

static char		*parse_grammar(t_lextab *lex)
{
	while (lex)
	{
		if (lex->prev == NULL)
		{
			if (lex->token == OPERATOR)
				return (lex->word);
		}
		if (lex->token == OPERATOR && lex->next && lex->next->token == OPERATOR)
		{
			if (is_redir(lex->subtok) && is_separ(lex->next->subtok))
				return (lex->next->word);
			else if (is_separ(lex->subtok) && is_separ(lex->next->subtok))
				return (lex->next->word);
			else if (is_redir(lex->subtok) && is_redir(lex->next->subtok))
				return (lex->next->word);
		}
		else if (lex->next == NULL)
			if (lex->token == OPERATOR)
				return (lex->word);
		lex = lex->next;
	}
	return (NULL);
}

static int		tokenise_operator(t_lextab *lex)
{
	char		*c;

	while (lex != NULL)
	{
		if (lex->token == OPERATOR)
		{
			if ((c = cmp_operand(lex->word)) != NULL)
				return (parse_error(c));
			if ((lex->subtok = add_operator(lex->word)) > AMPERSAND)
			{
				ft_putendl_fd("Programming error", STDERR_FILENO);
				return (-1);
			}
		}
		lex = lex->next;
	}
	return (0);
}

static int		tokenise_other(t_lextab *lex)
{
	while (lex != NULL)
	{
		if (lex->token != OPERATOR && lex->token != WORD)
			add_simple_token(lex->prev, lex, lex->next);
		lex = lex->next;
	}
	return (0);
}

int				parse_and_tokenise(void)
{
	char		*error;
	t_parser	*parser;

	parser = g_memory(S_PARSER, 0);
	if (tokenise_operator(parser->lex) == -1)
		return (-1);
	tokenise_other(parser->lex);
	error = parse_grammar(parser->lex);
	if (error != NULL)
	{
		return (parse_error(error));
	}
	return (0);
}
