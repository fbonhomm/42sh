/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:32:40 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/14 17:42:22 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

void		error(char *s)
{
	if (s != NULL)
		ft_putstr_fd(s, STDERR_FILENO);
	ft_putstr_fd(" : ", STDERR_FILENO);
	if (g_error != NULL)
		ft_putendl_fd(g_error, STDERR_FILENO);
	else
		ft_putendl_fd("Undefined error: 0", STDERR_FILENO);
	g_error = NULL;
}

int			parse_error(char *c)
{
	ft_putstr_fd("42sh: parse error near ", STDERR_FILENO);
	write(STDERR_FILENO, "\'", 1);
	write(STDERR_FILENO, c, 2);
	write(STDERR_FILENO, "\'", 1);
	write(STDERR_FILENO, "\n", 1);
	return (-1);
}

int			builtin_error(char *builtin, char *file)
{
	if (builtin != NULL)
		ft_putstr_fd(builtin, STDERR_FILENO);
	if (g_error != NULL)
	{
		if (g_error == ENVH)
		{
			ft_putendl_fd(g_error, STDERR_FILENO);
			return (-1);
		}
		ft_putstr_fd(g_error, STDERR_FILENO);
	}
	if (file != NULL)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putendl_fd(file, STDERR_FILENO);
	}
	else
		ft_putendl_fd("", STDERR_FILENO);
	g_error = NULL;
	return (-1);
}

int			int_error(char *value)
{
	g_error = value;
	return (-1);
}

int			error_redirection(char *error, int fd)
{
	ft_putstr_fd("42sh: error: ", STDERR_FILENO);
	if (fd != -1)
		ft_putnbr_fd(fd, STDERR_FILENO);
	ft_putchar_fd(' ', STDERR_FILENO);
	ft_putendl_fd(error, STDERR_FILENO);
	return (-1);
}
