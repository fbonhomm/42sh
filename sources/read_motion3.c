/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_motion3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:34:47 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 18:57:52 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int				cur_motion_altup(t_win *term, int key)
{
	t_cmline	*tmp;
	int			column;

	tmp = term->all_act->cm;
	column = term->win_column;
	if (tmp->cur_pos_y > 0)
	{
		while (column > 0)
		{
			cur_motion_left(term, key);
			column--;
		}
	}
	return (1);
}

int				cur_motion_altdown(t_win *term, int key)
{
	t_cmline	*tmp;
	int			column;

	tmp = term->all_act->cm;
	if (tmp->nb_line_toline > tmp->cur_pos_y)
	{
		column = term->win_column;
		while (column > 0)
		{
			cur_motion_right(term, key);
			column--;
		}
	}
	return (1);
}

int				cur_motion_end(t_win *term, int key)
{
	t_cmline	*tmp;

	tmp = term->all_act->cm;
	while (42)
	{
		while (tmp->ch_after_cur > -1)
			cur_motion_right(term, key);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (1);
}

int				cur_motion_home(t_win *term, int key)
{
	t_cmline	*tmp;
	int			nb;

	tmp = term->all_act->cm;
	while (42)
	{
		nb = tmp->cur_pos_line;
		while (nb > -1)
		{
			cur_motion_left(term, key);
			--nb;
		}
		if (tmp->prompt_len > 0 || tmp->prev == NULL)
			break ;
		tmp = tmp->prev;
	}
	return (1);
}

int				del_character(t_win *term, int key)
{
	int			nb;

	if ((term->all_act->cm->cur_pos_x == 0 && term->all_act->cm->cur_pos_y == 0)
		&& (!term->all_act->cm->prev || term->all_act->cm->prompt_len > 0
			|| !term->all_act->cm->prev->line))
		return (1);
	term->all_act->nb_ch--;
	if (term->all_act->cm->line == NULL)
		return (cur_motion_left(term, key));
	if (term->all_act->cm->cur_pos_x > 0)
		cur_motion_handler(LEFT, 1);
	else if (cur_motion_handler(UP, 1) && term->all_act->cm->cur_pos_y == 0)
	{
		term->all_act->cm = term->all_act->cm->prev;
		cur_motion_handler(RIGHT, term->all_act->cm->cur_pos_term);
	}
	else
		cur_motion_handler(RIGHT, term->win_column);
	conf_delete(term, &term->all_act->cm);
	delete_left_key(&term->all_act->cm->line, term->all_act->cm->cur_pos_line);
	tputs(tgetstr("cd", NULL), 1, shput);
	nb = print_deletion(term);
	while (nb-- > 0)
		cur_motion_left(term, key);
	return (1);
}
