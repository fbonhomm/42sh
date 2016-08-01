/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:33:39 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:33:40 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int					add_file_redir(t_lextab *lex, t_redir **redir)
{
	t_redir			*new;
	char			*path;

	path = "/tmp/";
	new = (t_redir *)ft_memalloc(sizeof(t_redir));
	if (new == NULL)
		return (-1);
	new->type = lex->subtok;
	if (lex->prev && lex->prev->token == IO_NUMBER)
		new->io_num = ft_atoi(lex->prev->word);
	else
		new->io_num = -1;
	if (lex->next && lex->next->token == IO_FILE)
	{
		if (lex->next->subtok == DLESS)
			new->name_io_file = ft_strjoin(path, lex->next->word);
		else
			new->name_io_file = ft_strdup(lex->next->word);
	}
	add_lst_redir(redir, new);
	return (0);
}

void				add_lst_allcmd(t_allcmd *allnew)
{
	t_allcmd	*tmp;
	t_parser	*parser;

	parser = g_memory(S_PARSER, 0);
	if (parser->allcmd == NULL)
		parser->allcmd = allnew;
	else
	{
		tmp = parser->allcmd;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = allnew;
	}
}

void				add_lst_cmd(t_cmd **cmd, t_cmd *new_cmd)
{
	t_cmd			*tmp;

	tmp = *cmd;
	if (*cmd == NULL)
		*cmd = new_cmd;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_cmd;
		new_cmd->prev = tmp;
	}
}

void				add_lst_redir(t_redir **redir, t_redir *new)
{
	t_redir			*tmp;

	tmp = *redir;
	if (*redir == NULL)
		*redir = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

int					create_cmd_lst(t_lextab *lex)
{
	t_lextab		*begin;

	begin = lex;
	while (lex != NULL)
	{
		if ((lex->token == OPERATOR && lex->subtok > PIPE) || lex->next == NULL)
		{
			if (add_allcmd(begin, lex) == -1)
				return (-1);
			begin = lex->next;
		}
		lex = lex->next;
	}
	return (0);
}
