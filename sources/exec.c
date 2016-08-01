/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:32:46 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/04 18:22:06 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

void				exec_binary(t_cmd *cmd)
{
	if (cmd->bin[0] == '/' || cmd->bin[0] == '.')
		execve(cmd->bin, cmd->arg_list, g_env);
	g_error = EFOUND;
	error_exec(cmd->bin);
	exit(127);
}

void				exec_builtin(t_cmd *cmd)
{
	if (builtin_core(cmd) == -1)
	{
		error(cmd->bin);
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

int					exec_child(t_cmd *cmd, t_input *input_tab)
{
	if (cmd->next != NULL)
	{
		if (close_fd(cmd->pipe[0]) != 0)
			return (-1);
	}
	if (cmd->prev != NULL)
	{
		if (dup_fd(cmd->prev->pipe[0], input_tab[0].fd) == -1)
			return (-1);
	}
	if (cmd->next != NULL)
	{
		if (dup_fd(cmd->pipe[1], input_tab[1].fd) == -1)
			return (-1);
	}
	if (apply_redirection(cmd->redir, input_tab) == -1)
		return (-1);
	if (cmd->bin_type == BIN && parser_path(cmd->bin, '-', S_IXUSR) == -1)
	{
		error_exec(cmd->bin);
		return (-1);
	}
	cmd->bin_type == BUILTIN ? exec_builtin(cmd) : exec_binary(cmd);
	return (-1);
}

int					exec_exec(t_cmd *cmd, pid_t *child_tab, t_input *input_tab)
{
	if ((*child_tab = fork_child(child_tab)) == -1)
		return (-1);
	if (*child_tab == 0)
		if (exec_child(cmd, input_tab) == -1)
			exit(EXIT_FAILURE);
	return (0);
}

int					exec_cmd(t_cmd *cmd, pid_t *child_tab, t_input *input_tab)
{
	int				i;

	i = 0;
	while (cmd != NULL)
	{
		if (cmd->next != NULL)
			if (pipe_fd(cmd->pipe) == -1)
				return (-1);
		if (exec_exec(cmd, &child_tab[i], input_tab) == -1)
			return (-1);
		if (cmd->next != NULL)
			if (close_fd(cmd->pipe[1]) != 0)
				return (-1);
		++i;
		cmd = cmd->next;
	}
	return (0);
}
