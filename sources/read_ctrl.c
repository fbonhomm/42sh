/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ctrl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:34:18 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:34:19 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int				paste_line(t_win *term, int key)
{
	t_line		*copy;

	UNUSED(key);
	copy = term->copy;
	while (copy != NULL)
	{
		print_add_character(term, copy->ch);
		copy = copy->next;
	}
	return (1);
}

int				copy_left_line(t_win *term, int key)
{
	int			ch;
	int			pos;

	ch = term->all_act->cm->cur_pos_line;
	pos = 0;
	if (term->copy != NULL)
		free_line(&term->copy);
	while (term->all_act->cm->cur_pos_x != 0
		|| term->all_act->cm->cur_pos_y != 0)
		cur_motion_left(term, key);
	while (ch > 0)
	{
		cur_motion_right(term, key);
		add_key(term->all_act->cm->cur->ch, &term->copy, pos);
		++pos;
		--ch;
	}
	return (1);
}

int				copy_right_line(t_win *term, int key)
{
	int			pos;

	pos = 0;
	if (term->copy != NULL)
		free_line(&term->copy);
	while (term->all_act->cm->ch_after_cur != -1)
	{
		cur_motion_right(term, key);
		add_key(term->all_act->cm->cur->ch, &term->copy, pos);
		++pos;
	}
	while (pos > 0)
	{
		cur_motion_left(term, key);
		--pos;
	}
	return (1);
}

int				cut_left_line(t_win *term, int key)
{
	int			ch;
	int			pos;

	ch = term->all_act->cm->cur_pos_line;
	pos = 0;
	if (term->copy != NULL)
		free_line(&term->copy);
	while (term->all_act->cm->cur_pos_x || term->all_act->cm->cur_pos_y)
		cur_motion_left(term, key);
	while (ch > 0)
	{
		cur_motion_right(term, key);
		add_key(term->all_act->cm->cur->ch, &term->copy, pos);
		++pos;
		--ch;
	}
	while (pos > 0)
	{
		del_character(term, key);
		--pos;
	}
	return (1);
}

int				cut_right_line(t_win *term, int key)
{
	int			pos;
	int			ch;

	pos = 0;
	ch = term->all_act->cm->ch_after_cur;
	if (term->copy != NULL)
		free_line(&term->copy);
	while (term->all_act->cm->ch_after_cur != -1)
	{
		cur_motion_right(term, key);
		add_key(term->all_act->cm->cur->ch, &term->copy, pos);
		++pos;
	}
	while (ch-- > -1)
		del_character(term, key);
	return (1);
}
