/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:35:16 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/04 18:16:50 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int					apply_dless(t_redir redir, t_input *input_tab)
{
	static int		flags = O_RDONLY;
	int				io_num;

	if (redir.io_num > 254)
		return (error_redirection("bad file descriptor", redir.io_num));
	io_num = redir.io_num == -1 ? STDIN_FILENO : redir.io_num;
	if (close_file_descriptor(&input_tab[io_num]) == -1)
		return (-1);
	if (open_file_descriptor(&input_tab[io_num], flags, "/tmp/heredoc")
		== -1)
		return (-1);
	input_tab[io_num].re = 0;
	return (0);
}

int					apply_less(t_redir redir, t_input *input_tab)
{
	static int		flags = O_RDONLY;
	int				io_num;

	if (redir.io_num > 254)
		return (error_redirection("bad file descriptor", redir.io_num));
	io_num = redir.io_num == -1 ? STDIN_FILENO : redir.io_num;
	if (close_file_descriptor(&input_tab[io_num]) == -1)
		return (-1);
	if (open_file_descriptor(&input_tab[io_num], flags, redir.name_io_file)
		== -1)
		return (-1);
	input_tab[io_num].re = 0;
	return (0);
}

int					apply_dgreat(t_redir redir, t_input *input_tab)
{
	static int		flags = O_WRONLY | O_CREAT | O_APPEND;
	int				io_num;

	if (redir.io_num > 254)
		return (error_redirection("bad file descriptor", redir.io_num));
	io_num = redir.io_num == -1 ? STDOUT_FILENO : redir.io_num;
	if (close_file_descriptor(&input_tab[io_num]) == -1)
		return (-1);
	if (open_file_descriptor(&input_tab[io_num], flags, redir.name_io_file)
		== -1)
		return (-1);
	input_tab[io_num].wr = 0;
	return (0);
}

int					apply_great(t_redir redir, t_input *input_tab)
{
	static int		flags = O_WRONLY | O_CREAT | O_TRUNC;
	int				io_num;

	if (redir.io_num > 254)
		return (error_redirection("bad file descriptor", redir.io_num));
	io_num = redir.io_num == -1 ? STDOUT_FILENO : redir.io_num;
	if (close_file_descriptor(&input_tab[io_num]) == -1)
		return (-1);
	if (open_file_descriptor(&input_tab[io_num], flags, redir.name_io_file)
		== -1)
		return (-1);
	input_tab[io_num].wr = 0;
	return (0);
}

int					apply_lessand(t_redir redir, t_input *input_tab)
{
	int				io_num;
	int				io_file;

	io_file = ft_atoi(redir.name_io_file);
	if (redir.io_num > 254 || io_file > 254)
		return (error_redirection("bad file descriptor", redir.io_num > 254 ?
		redir.io_num : io_file));
		io_num = redir.io_num == -1 ? STDIN_FILENO : redir.io_num;
	if (io_file == 0 && ft_strcmp(redir.name_io_file, "0") != 0 &&
		ft_strcmp(redir.name_io_file, "-") != 0)
		return (error_redirection("ambigous redirection", -1));
	else if (input_tab[io_file].close == -1 || input_tab[io_file].re == -1)
		return (error_redirection("bad file descriptor", io_file));
	if (close_file_descriptor(&input_tab[io_num]) == -1)
		return (-1);
	if (ft_strcmp(redir.name_io_file, "-") != 0)
		dup2(input_tab[io_file].fd, input_tab[io_num].fd);
	return (0);
}
