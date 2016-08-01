/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_backquote.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriot <eduriot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:33:05 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/15 10:25:04 by eduriot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

char				*remove_backquote(char *str)
{
	str = ft_memmove(str, str + 1, (ft_strlen(str) - 2));
	str[ft_strlen(str) - 2] = '\0';
	return (str);
}

char				*read_pipe(int fd)
{
	char			*str;
	char			*tmp;
	char			line[4096];

	str = NULL;
	ft_bzero(line, 4096);
	while (read(fd, line, 4095))
	{
		if (!str)
			str = ft_strdup(line);
		else
		{
			tmp = ft_strjoin(str, line);
			ft_strdel(&str);
			str = ft_strdup(tmp);
			ft_strdel(&tmp);
		}
		ft_bzero(line, 4096);
	}
	return (str);
}

char				*exec_backquote(char *tmp)
{
	pid_t			father;
	int				pipefd[2];
	char			*tmp2;

	tmp2 = NULL;
	if (pipe_fd(pipefd) == -1)
		return (NULL);
	if (fork_child(&father) == -1)
		return (NULL);
	if (father > 0)
	{
		close(pipefd[1]);
		wait(&father);
		return (tmp2 = read_pipe(pipefd[0]));
	}
	if (father == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		free_brain(S_PARSER);
		exit(parser(tmp) == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
	}
	return (tmp2);
}

char				*format_backquote(char *str)
{
	char			*tmp;
	char			*tmp2;
	int				len;

	tmp = ft_strdup(str);
	tmp = remove_backquote(tmp);
	tmp2 = exec_backquote(tmp);
	len = ft_strlen(tmp2);
	if (tmp2)
	{
		while (tmp2[len - 1] == '\n')
		{
			tmp2[len - 1] = '\0';
			len--;
		}
	}
	ft_strdel(&tmp);
	if (!tmp2)
		return (NULL);
	return (tmp2);
}
