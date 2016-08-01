/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_print2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:35:02 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:35:02 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int				print_character(t_win *term, int key)
{
	conf_print(term, &term->all_act->cm);
	print_key(term->all_act->cm->cur_pos_term, key);
	return (1);
}

int				print_deletion(t_win *term)
{
	t_line		*line;
	int			nb;

	nb = 0;
	line = term->all_act->cm->cur->next;
	while (term->all_act->cm != NULL)
	{
		term->all_act->cm->ch_after_cur = -1;
		while (line != NULL)
		{
			conf_del_print(term, &term->all_act->cm);
			ft_putchar_fd(line->ch, STDIN_FILENO);
			if (term->all_act->cm->cur_pos_x == 0)
				cur_motion_handler(DOWN, 1);
			line = line->next;
			++nb;
		}
		if (term->all_act->cm->next == NULL)
			break ;
		++nb;
		ft_putchar_fd('\n', STDIN_FILENO);
		term->all_act->cm = term->all_act->cm->next;
		line = term->all_act->cm->line;
	}
	return (nb);
}
