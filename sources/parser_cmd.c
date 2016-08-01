/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 10:47:29 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/17 13:48:35 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

void				set_input_tab(t_input *input_tab)
{
	int				i;

	i = 0;
	while (i < OPEN_MAX_INPUT)
	{
		if (input_tab[i].fd > 2)
			close(input_tab[i].fd);
		++i;
	}
	ft_memset(input_tab, -1, sizeof(*input_tab) * OPEN_MAX_INPUT);
	input_tab[0].fd = STDIN_FILENO;
	input_tab[0].wr = 0;
	input_tab[0].re = 0;
	input_tab[0].close = 0;
	input_tab[1].fd = STDOUT_FILENO;
	input_tab[1].wr = 0;
	input_tab[1].re = 0;
	input_tab[1].close = 0;
	input_tab[2].fd = STDERR_FILENO;
	input_tab[2].wr = 0;
	input_tab[2].re = 0;
	input_tab[2].close = 0;
}

int					format_lextab2(t_lextab **begin)
{
	char			*tmp;
	t_parser		*parser;
	t_lextab		*lex_tmp;

	parser = g_memory(S_PARSER, 0);
	tmp = parser->lex->word;
	if ((parser->lex->word =
		ft_strjoin(parser->lex->prev->word, parser->lex->word)) == NULL)
		return (-1);
	ft_strdel(&tmp);
	ft_strdel(&parser->lex->prev->word);
	parser->lex->no_parse = parser->lex->prev->no_parse;
	if (parser->lex->prev->prev != NULL)
	{
		parser->lex->prev->prev->next = parser->lex;
		lex_tmp = parser->lex->prev;
		parser->lex->prev = parser->lex->prev->prev;
		free(lex_tmp);
		return (0);
	}
	*begin = parser->lex;
	free((*begin)->prev);
	(*begin)->prev = NULL;
	return (0);
}

int					format_lextab(void)
{
	t_lextab		*begin;
	t_parser		*parser;

	parser = g_memory(S_PARSER, 0);
	begin = parser->lex;
	while (parser->lex)
	{
		if (parser->lex->prev && parser->lex->prev->separator == 0
			&& parser->lex->prev->token != OPERATOR
			&& parser->lex->token != OPERATOR)
			format_lextab2(&begin);
		parser->lex = parser->lex->next;
	}
	parser->lex = begin;
	return (0);
}

int					launch_allcmd(t_allcmd *all, pid_t nb_child)
{
	while (all)
	{
		nb_child = count_child(all->cmd);
		if (all->cmd->bin_type == BUILTIN
		&& ft_strcmp(all->cmd->arg_list[0], "env") != 0
		&& ft_strcmp(all->cmd->arg_list[0], "echo") != 0
		&& ((nb_child == 0 && all->cmd->redir == NULL)
		|| ft_strcmp(all->cmd->arg_list[0], "cd") == 0))
			builtin_core(all->cmd);
		else
		{
			if (!(all->child_tab = malloc(sizeof(pid_t) * nb_child + 1)))
				return (-1);
			set_input_tab(all->input_tab);
			if (exec_cmd(all->cmd, all->child_tab, all->input_tab) == -1
			|| last_ret(wait_child(all->child_tab, nb_child), 0) == -1
			|| remove_here_document(all->cmd) == -1)
				return (-1);
			if ((last_ret(0, 1) == 0 && all->what_if == OR_IF)
				|| (last_ret(0, 1) != 0 && all->what_if == AND_IF))
				break ;
		}
		all = all->next;
	}
	return (0);
}

int					parser(char *str)
{
	t_parser		*parser;
	pid_t			nb_child;

	nb_child = 0;
	parser = g_memory(S_PARSER, 0);
	parser->allcmd = NULL;
	if (str == NULL)
		return (0);
	if (exe_funct(str) == 0)
		return (0);
	if (lexer(str) == -1)
		return (-1);
	if (format_lextab() == -1)
		return (-1);
	if (parser->lex == NULL)
		return (g_error == NULL ? 0 : -1);
	if (parse_and_tokenise() == -1)
		return (0);
	if (create_cmd_lst(parser->lex) == -1)
		return (g_error == EFOUND ? 0 : -1);
	if (add_here_document(parser->allcmd) == -1 && g_error != SIGCTRL)
		return (-1);
	if (launch_allcmd(parser->allcmd, nb_child) == -1)
		return (-1);
	return (0);
}
