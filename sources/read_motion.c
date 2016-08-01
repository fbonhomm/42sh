/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_motion.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:34:31 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:34:32 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int				cur_motion_forward(t_win *term, int key)
{
	t_line		*line;

	line = term->all_act->cm->cur;
	while (line && line->ch == ' ')
	{
		cur_motion_right(term, key);
		line = line->next;
	}
	while (line && line->ch != ' ')
	{
		cur_motion_right(term, key);
		line = line->next;
	}
	return (1);
}

int				cur_motion_backward(t_win *term, int key)
{
	t_line		*line;

	line = term->all_act->cm->cur;
	while (line && line->ch == ' ')
	{
		cur_motion_left(term, key);
		line = line->prev;
	}
	while (line && line->ch != ' ')
	{
		cur_motion_left(term, key);
		line = line->prev;
	}
	return (1);
}

int				cur_motion_handler(int direction, int nb_occurence)
{
	static char *str[4] = {"up", "do", "le", "nd"};
	int			i;

	if (direction == UP)
		i = 0;
	else if (direction == DOWN)
		i = 1;
	else if (direction == LEFT)
		i = 2;
	else if (direction == RIGHT)
		i = 3;
	while (nb_occurence > 0)
	{
		tputs(tgetstr(str[i], NULL), 1, shput);
		--nb_occurence;
	}
	return (1);
}
