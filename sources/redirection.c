/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:35:12 by ksoulard          #+#    #+#             */
/*   Updated: 2016/07/26 09:58:37 by eduriot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int					close_file_descriptor(t_input *input)
{
	if (input->fd != -1)
	{
		if (close_fd(input->fd) == -1)
			return (-1);
		input->wr = -1;
		input->re = -1;
		input->close = -1;
	}
	return (0);
}

int					open_file_descriptor(t_input *input, int flags,
					char const *file)
{
	input->fd = open(file, flags, 0644);
	if (input->fd == -1)
	{
		g_error = ENONEX;
		return (-1);
	}
	input->close = 0;
	return (0);
}

int					apply_lessgreat(t_redir red, t_input *input_tab)
{
	static int		flags = O_RDWR | O_CREAT | O_TRUNC;
	int				io_num;

	if (red.io_num > 254)
		return (error_redirection("bad file descriptor", red.io_num));
	io_num = red.io_num == -1 ? STDIN_FILENO : red.io_num;
	if (close_file_descriptor(&input_tab[io_num]) == -1)
		return (-1);
	if (open_file_descriptor(&input_tab[io_num], flags, red.name_io_file) == -1)
		return (-1);
	input_tab[io_num].re = 0;
	input_tab[io_num].wr = 0;
	return (0);
}

int					apply_greatand(t_redir redir, t_input *input_tab)
{
	int				io_num;
	int				io_file;

	io_file = ft_atoi(redir.name_io_file);
	if (redir.io_num > 254 || io_file > 254)
		return (error_redirection("bad file descriptor",
	redir.io_num > 254 ? redir.io_num : io_file));
		io_num = redir.io_num == -1 ? STDOUT_FILENO : redir.io_num;
	if (io_file == 0 && ft_strcmp(redir.name_io_file, "0") != 0
		&& ft_strcmp(redir.name_io_file, "-") != 0)
		return (error_redirection("ambigous redirection", -1));
	else if (input_tab[io_file].close == -1 || input_tab[io_file].wr == -1)
		return (error_redirection("bad file descriptor", io_file));
	if (close_file_descriptor(&input_tab[io_num]) == -1)
		return (-1);
	if (ft_strcmp(redir.name_io_file, "-") != 0)
	{
		// close(input_tab[io_file].fd);
		dup2(input_tab[io_file].fd, input_tab[io_num].fd);
	}
	return (0);
}

int					apply_redirection(t_redir *redir, t_input *input_tab)
{
	int				(*f_redir[LESSGREAT + 1])(t_redir, t_input *);
	t_redir			*tmp;

	tmp = redir;
	f_redir[0] = apply_great;
	f_redir[1] = apply_dgreat;
	f_redir[2] = apply_less;
	f_redir[3] = apply_dless;
	f_redir[4] = apply_greatand;
	f_redir[5] = apply_lessand;
	f_redir[6] = apply_lessgreat;
	while (tmp != NULL)
	{
		if (f_redir[tmp->type](*tmp, input_tab) == -1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
