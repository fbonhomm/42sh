/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:35:44 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/06 13:44:53 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int					close_fd(int fd)
{
	if (close(fd) == -1)
	{
		g_error = ECLOSE;
		return (-1);
	}
	return (0);
}

int					pipe_fd(int pipefd[2])
{
	if (pipe(pipefd) == -1)
	{
		g_error = EMANYF;
		return (-1);
	}
	return (0);
}

int					dup_fd(int fd1, int fd2)
{
	if (close_fd(fd2) == -1)
		return (-1);
	if (dup2(fd1, fd2) == -1)
	{
		g_error = EBOPEN;
		return (-1);
	}
	return (0);
}

int					fork_child(pid_t *child)
{
	*child = fork();
	if (*child == -1)
	{
		g_error = ECHILDS;
		return (-1);
	}
	return (*child);
}

void				error_exec(char *c)
{
	ft_putstr_fd("42sh: ", STDERR_FILENO);
	if (g_error == ENONEX)
		g_error = EFOUND;
	error(c);
	exit(127);
}
