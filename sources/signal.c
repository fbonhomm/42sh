/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:35:24 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/04 19:08:22 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static void				signal_handler(int sign, siginfo_t *siginfo,
						void *context)
{
	t_win				*term;

	(void)siginfo;
	(void)context;
	if (sign == SIGWINCH)
	{
		ft_putendl_fd("", STDIN_FILENO);
		term = g_memory(S_WIN, 0);
		if (term->all_act != NULL)
		{
			if (tgetent(NULL, term->term_name) == -1)
				int_error(ETERM);
			term->win_column = tgetnum("co");
			term->win_line = tgetnum("li");
			g_error = ESIGWINCH;
		}
	}
}

int						signal_init(void)
{
	struct sigaction	action;

	ft_memset(&action, 0, sizeof(action));
	action.sa_sigaction = &signal_handler;
	action.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGQUIT, &action, NULL);
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGTSTP, &action, NULL);
	sigaction(SIGWINCH, &action, NULL);
	return (0);
}
