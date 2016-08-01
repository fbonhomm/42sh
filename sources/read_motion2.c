/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_motion2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:34:39 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/14 17:43:19 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int				cur_motion_up(t_win *term, int key)
{
	if (term->all_act->next == NULL
		|| (ft_strcmp(term->all_act->cm->prompt_name, "42sh> ") != 0
			&& ft_strcmp(term->all_act->cm->prompt_name, "") != 0))
		return (1);
	cur_motion_home(term, key);
	tputs(tgetstr("cd", NULL), 1, shput);
	term->all_act = term->all_act->next;
	init_history(&term->all_act->cm);
	while (42)
	{
		term->all_act->nb_ch +=
			print_history_line(term, term->all_act->cm->line);
		if (term->all_act->cm->next == NULL)
			break ;
		cur_motion_handler(DOWN, 1);
		term->all_act->cm = term->all_act->cm->next;
		term->all_act->nb_ch =
			term->all_act->prev->nb_ch + term->all_act->nb_ch;
		conf_history(term, &term->all_act->cm);
	}
	new_data_for_end(&term->all_act->cm);
	return (1);
}

int				cur_motion_down(t_win *term, int key)
{
	if (term->all_act->prev == NULL
		|| (ft_strcmp(term->all_act->cm->prompt_name, "42sh> ") != 0
			&& ft_strcmp(term->all_act->cm->prompt_name, "") != 0))
		return (1);
	cur_motion_home(term, key);
	tputs(tgetstr("cd", NULL), 1, shput);
	term->all_act = term->all_act->prev;
	init_history(&term->all_act->cm);
	while (42)
	{
		term->all_act->nb_ch +=
			print_history_line(term, term->all_act->cm->line);
		if (term->all_act->cm->next == NULL)
			break ;
		cur_motion_handler(DOWN, 1);
		term->all_act->cm = term->all_act->cm->next;
		conf_history(term, &term->all_act->cm);
	}
	new_data_for_end(&term->all_act->cm);
	return (1);
}

int				cur_motion_right(t_win *term, int key)
{
	UNUSED(key);
	if (term->all_act->cm->ch_after_cur == -1 && !term->all_act->cm->next)
		return (1);
	if (term->all_act->cm->ch_after_cur > -1)
	{
		if (term->all_act->cm->cur_pos_term != term->win_column - 1)
			cur_motion_handler(RIGHT, 1);
		else
			cur_motion_handler(DOWN, 1);
		conf_motion_right(term, &term->all_act->cm);
		return (1);
	}
	new_cmline_for_read(&term->all_act->cm, RIGHT);
	cur_motion_handler(DOWN, 1);
	term->all_act->cm->cur_pos_y_tocm =
		term->all_act->cm->prev->cur_pos_y_tocm + 1;
	term->all_act->cm->nb_line_tocm = term->all_act->cm->prev->nb_line_tocm;
	return (1);
}

int				cur_motion_left(t_win *term, int key)
{
	t_cmline	*tmp;

	UNUSED(key);
	tmp = term->all_act->cm;
	if (tmp->cur_pos_x == 0 && tmp->cur_pos_y == 0 && (tmp->prev == NULL ||
		tmp->prompt_len > 0))
		return (1);
	if (tmp->cur_pos_x != 0)
	{
		cur_motion_handler(LEFT, 1);
		conf_motion_left(term, &term->all_act->cm);
		return (1);
	}
	cur_motion_handler(UP, 1);
	if (tmp->cur_pos_y == 0)
	{
		new_cmline_for_read(&term->all_act->cm, LEFT);
		cur_motion_handler(RIGHT, term->all_act->cm->cur_pos_term);
		term->all_act->cm->nb_line_tocm = term->all_act->cm->next->nb_line_tocm;
		return (1);
	}
	conf_motion_left(term, &term->all_act->cm);
	cur_motion_handler(RIGHT, term->win_column);
	return (1);
}
