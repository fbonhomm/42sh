/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 13:04:03 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/04 18:12:30 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int			read_heredoc(int fd, char *end)
{
	char	*s;
	int		ret;

	s = NULL;
	ft_putstr_fd("Heredoc> ", STDOUT_FILENO);
	while ((ret = get_next_line(STDIN_FILENO, &s)) > 0)
	{
		if (ft_strcmp(s, end) == 0)
		{
			ft_strdel(&s);
			break ;
		}
		if (write(fd, s, ft_strlen(s)) == -1)
			return (-1);
		if (write(fd, "\n", 1) == -1)
			return (-1);
		ft_putstr_fd("Heredoc> ", STDOUT_FILENO);
		ft_strdel(&s);
	}
	return (ret);
}

static int	add_here_document_2(t_allcmd *all)
{
	int			fd;
	t_redir		*redir_begin;

	redir_begin = all->cmd->redir;
	while (all->cmd->redir != NULL)
	{
		if (all->cmd->redir->type == DLESS)
		{
			if ((fd = open("/tmp/heredoc", O_CREAT | O_WRONLY, 0644)) == -1)
				return (-1);
			if (read_heredoc(fd, all->cmd->redir->name_io_file) == -1)
				return (-1);
			if (close(fd) == -1)
				return (-1);
		}
		all->cmd->redir = all->cmd->redir->next;
	}
	all->cmd->redir = redir_begin;
	return (0);
}

int			add_here_document(t_allcmd *all)
{
	t_allcmd	*begin;
	t_cmd		*cmd_begin;

	begin = all;
	while (all != NULL)
	{
		cmd_begin = all->cmd;
		while (all->cmd != NULL)
		{
			if (add_here_document_2(all) == -1)
				return (-1);
			all->cmd = all->cmd->next;
		}
		all->cmd = cmd_begin;
		all = all->next;
	}
	all = begin;
	return (0);
}

int			remove_here_document(t_cmd *cmd)
{
	t_redir *tmp;
	t_cmd	*tmp_cmd;

	tmp_cmd = cmd;
	while (cmd != NULL)
	{
		tmp = cmd->redir;
		while (tmp != NULL)
		{
			if (tmp->type == DLESS)
			{
				if (unlink("/tmp/heredoc") == -1)
				{
					g_error = "ECLOSE";
					error("Here Doc");
					return (-1);
				}
			}
			tmp = tmp->next;
		}
		cmd = cmd->next;
	}
	cmd = tmp_cmd;
	return (0);
}
