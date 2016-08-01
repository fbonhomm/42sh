/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:35:48 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/04 19:13:30 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static void			free_allcmd(t_allcmd *allcmd)
{
	t_allcmd		*prev;
	int				i;

	i = 0;
	while (allcmd)
	{
		if (allcmd->cmd)
			free_cmd(&allcmd->cmd);
		if (allcmd->child_tab && *allcmd->child_tab)
		{
			while (allcmd->child_tab[i])
			{
				free(&allcmd->child_tab[i]);
				++i;
			}
		}
		free(allcmd->child_tab);
		prev = allcmd;
		allcmd = allcmd->next;
		free(prev);
	}
}

static void			free_lex(t_lextab **lex)
{
	t_lextab		*prev;

	while (*lex)
	{
		if ((*lex)->word)
			ft_strdel(&(*lex)->word);
		prev = *lex;
		*lex = (*lex)->next;
		free(prev);
	}
}

static void			free_parser(void)
{
	t_parser		*pars;

	pars = g_memory(S_PARSER, 0);
	if (pars->lex)
		free_lex(&pars->lex);
	if (pars->allcmd)
	{
		if (pars->allcmd)
			free_allcmd(pars->allcmd);
		pars->allcmd = NULL;
		pars->cmd = NULL;
		pars->redir = NULL;
		pars->lex = NULL;
	}
	pars = NULL;
}

static void			free_win(void)
{
	t_win			*win;
	t_line			*prev_copy;
	t_all			*prev;

	win = g_memory(S_WIN, 0);
	while (win->copy)
	{
		prev_copy = win->copy;
		win->copy = win->copy->next;
		free(win->copy);
	}
	while (win->all_save)
	{
		free_cmline(&win->all_save->cm);
		prev = win->all_save;
		win->all_save = win->all_save->next;
		free(prev);
	}
}

void				free_brain(int choice)
{
	if (choice == S_WIN || choice == S_ALL)
		free_win();
	if (choice == S_HASH || choice == S_ALL)
		free_hash();
	if (choice == S_PARSER || choice == S_ALL)
		free_parser();
}
