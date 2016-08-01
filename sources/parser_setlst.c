/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_setlst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:33:51 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/14 17:38:33 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

char		*g_builtin_tab[NBR_BUILTIN] = {
	"env",
	"setenv",
	"unsetenv",
	"cd",
	"exit",
	"echo",
	"set",
	"unset",
	"export"
};

static char			**add_arglist(int nb_arg, t_lextab *lex, t_lextab *end)
{
	int				pos;
	char			**arg_list;

	arg_list = (char **)ft_memalloc(sizeof(char *) * nb_arg + 1);
	if (arg_list == NULL)
		return (NULL);
	arg_list[nb_arg] = NULL;
	pos = 0;
	while (lex != end->next)
	{
		if (lex->token == WORD)
		{
			arg_list[pos] = lex->word;
			++pos;
		}
		lex = lex->next;
	}
	return (arg_list);
}

static char			*add_bin_name(t_lextab *lex, t_lextab *end)
{
	char			*path;
	int				i;
	t_hash			**hash;

	i = 0;
	hash = g_memory(S_HASH, 0);
	while (lex != end->next)
	{
		i = 0;
		if (lex->token == WORD)
		{
			while (g_builtin_tab[i] != NULL)
			{
				if (ft_strcmp(g_builtin_tab[i], lex->word) == 0)
					return (ft_strdup(lex->word));
				++i;
			}
			if (ft_strchr(lex->word, '/') || hash == NULL
			|| *hash == NULL || !(path = get_path_hash(lex->word, hash)))
				return (ft_strdup(lex->word));
			return (ft_strjoin(path, lex->word));
		}
		lex = lex->next;
	}
	return (NULL);
}

static int			add_builtin(t_cmd *new)
{
	int				i;

	i = 0;
	while (g_builtin_tab[i] != NULL)
	{
		if (ft_strcmp(g_builtin_tab[i], new->bin) == 0)
		{
			new->bin_type = BUILTIN;
			break ;
		}
		++i;
	}
	if (new->bin_type != BUILTIN)
		new->bin_type = BIN;
	return (0);
}

static int			add_cmd(t_cmd **cmd, t_lextab *lex, t_lextab *end)
{
	t_cmd			*new;
	t_lextab		*tmp;
	int				nb_arg;

	new = (t_cmd *)ft_memalloc(sizeof(t_cmd));
	if (new == NULL)
		return (int_error(EALLOC));
	nb_arg = 0;
	tmp = lex;
	while (lex != end->next)
	{
		if (lex->token == WORD)
			++nb_arg;
		if (lex->token == OPERATOR && lex->subtok < PIPE)
			add_file_redir(lex, &new->redir);
		lex = lex->next;
	}
	new->arg_list = add_arglist(nb_arg, tmp, end);
	new->bin = add_bin_name(tmp, end);
	if (new->bin == NULL)
		return (int_error(EFOUND));
	add_builtin(new);
	add_lst_cmd(cmd, new);
	return (0);
}

int					add_allcmd(t_lextab *lex, t_lextab *end)
{
	t_allcmd		*new;
	t_lextab		*begin;
	t_cmd			*cmd;

	cmd = NULL;
	new = (t_allcmd *)ft_memalloc(sizeof(t_allcmd));
	if (new == NULL)
		return (int_error(EALLOC));
	begin = lex;
	while (lex != end->next)
	{
		if ((lex->token == OPERATOR && lex->subtok == PIPE) || lex == end)
		{
			if (add_cmd(&cmd, begin, lex) == -1)
				return (-1);
			begin = lex->next;
		}
		lex = lex->next;
	}
	new->what_if = end->subtok;
	new->cmd = cmd;
	add_lst_allcmd(new);
	return (0);
}
