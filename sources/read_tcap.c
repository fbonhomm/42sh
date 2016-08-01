/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tcap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 08:27:57 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/02 15:32:22 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int							set_attr(void)
{
	static struct termios	*act;

	if (act == NULL)
	{
		if ((act = (struct termios *)malloc(sizeof(struct termios))) == NULL)
			return (int_error(EALLOC));
		if (!g_error && tcgetattr(STDIN_FILENO, act) == -1)
			return (int_error(EGETCAP));
		ft_bzero(act, sizeof(act));
		act->c_lflag &= ~(ECHO | ICANON);
		act->c_lflag |= ISIG;
		act->c_oflag |= ~(OCRNL);
		act->c_cc[VMIN] = 1;
		act->c_cc[VTIME] = 0;
		act->c_cc[VINTR] = 1;
	}
	if (tcsetattr(STDIN_FILENO, TCSANOW, act) == -1)
		return (int_error(ESETCAP));
	return (0);
}

int							unset_attr(void)
{
	static struct termios	*save;

	if (save == NULL)
	{
		if ((save = malloc(sizeof(struct termios))) == NULL)
			return (int_error(EALLOC));
		if (tcgetattr(STDIN_FILENO, save) == -1)
			return (int_error(EGETCAP));
	}
	if (tcsetattr(STDIN_FILENO, TCSANOW, save) == -1)
		return (int_error(ESETCAP));
	return (0);
}

int							init_termcaps(void)
{
	t_win					*term;

	term = g_memory(S_WIN, 0);
	term->term_name = get_env_val("TERM");
	term->all_save = NULL;
	term->all_act = NULL;
	term->quote = 0;
	term->copy = NULL;
	if (term->term_name == NULL)
		term->term_name = ft_strdup("xterm-256color");
	if (term->term_name == NULL)
		return (int_error(EALLOC));
	if (tgetent(NULL, term->term_name) == -1 || unset_attr() == -1)
		return (int_error(ETERM));
	term->win_column = tgetnum("co");
	term->win_line = tgetnum("li");
	if (term->win_column == -1 || term->win_line == -1)
		g_error = ETERMERR;
	return (g_error == NULL ? 0 : -1);
}
