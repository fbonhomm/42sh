/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:40:55 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 23:01:03 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>
#include <parser.h>
#include "set.h"

int					parser_bis(char *str)
{
	t_parser		*parser;
	pid_t			nb_child;

	nb_child = 0;
	parser = g_memory(S_PARSER, 0);
	parser->allcmd = NULL;
	if (str == NULL)
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

void				replace_dol(char **str, char **cmd, int nbr)
{
	int				i;
	int				c;
	char			**tmp;

	i = -1;
	tmp = ft_split_mult(4, *str, ' ', '\t', '\n', '\r');
	while (cmd[nbr])
		nbr++;
	while (tmp[++i])
	{
		if (tmp[i][0] == '$')
		{
			tmp[i]++;
			c = ft_atoi(tmp[i]);
			tmp[i]--;
			if (nbr > c)
			{
				ft_free(&tmp[i]);
				tmp[i] = cmd[c];
			}
		}
	}
	ft_free(str);
	*str = ft_tab_to_str(tmp, ' ');
}

int					search_dollar(char *str)
{
	int				i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '$')
			return (1);
	}
	return (0);
}

void				command_funct(t_funct *f, char **cmd, int i)
{
	pid_t			child;

	while (f)
	{
		if (ft_strcmp(cmd[0], f->key) == 0)
		{
			while (f->content[i])
			{
				if ((child = fork()) == 0)
				{
					if ((search_dollar(f->content[i])))
						replace_dol(&f->content[i], cmd, 0);
					parser_bis(f->content[i]);
					exit(0);
				}
				wait(NULL);
				i++;
			}
			break ;
		}
		if (ft_sort_str(cmd[0], f->key) == 1)
			f = f->right;
		else
			f = f->left;
	}
}

int					exe_funct(char *cmd)
{
	char			**tmp;

	if (!cmd)
		return (-1);
	tmp = ft_split_mult(4, cmd, ' ', '\t', '\n', '\r');
	if (exist_funct(g_tree->funct, tmp[0]))
		command_funct(g_tree->funct, tmp, 0);
	else
	{
		ft_free_array(&tmp);
		return (-1);
	}
	ft_free_array(&tmp);
	return (0);
}
