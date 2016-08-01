/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_free2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:35:54 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/06 14:05:10 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"

void				free_redir(t_redir **redir)
{
	t_redir			*prev;

	while (*redir)
	{
		if ((*redir)->name_io_file)
			ft_strdel(&(*redir)->name_io_file);
		prev = *redir;
		(*redir) = (*redir)->next;
		free(prev);
	}
}

void				free_cmd(t_cmd **cmd)
{
	t_cmd			*prev;

	while (*cmd)
	{
		if ((*cmd)->bin)
			ft_strdel(&(*cmd)->bin);
		if ((*cmd)->arg_list)
			free((*cmd)->arg_list);
		if ((*cmd)->heredoc)
			ft_strdel(&(*cmd)->heredoc);
		if ((*cmd)->redir)
			free_redir(&(*cmd)->redir);
		if ((*cmd)->pipe[0] > 0)
			close((*cmd)->pipe[0]);
		(*cmd)->redir = NULL;
		prev = (*cmd);
		*cmd = (*cmd)->next;
		free(prev);
	}
}

void				free_hash(void)
{
	t_hash			**hash;
	int				i;
	t_lhash			*prev;

	hash = g_memory(S_HASH, 0);
	if (hash == NULL)
		return ;
	i = 0;
	while (hash[i])
	{
		while (hash[i]->lhash)
		{
			if (hash[i]->lhash->name)
				ft_strdel(&hash[i]->lhash->name);
			if (hash[i]->lhash->path)
				ft_strdel(&hash[i]->lhash->path);
			prev = hash[i]->lhash;
			hash[i]->lhash = hash[i]->lhash->next;
			free(prev);
		}
		free(hash[i]);
		i++;
	}
	free(hash);
	g_memory(S_HASH, -1);
}
