/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:34:09 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:34:10 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

void			conf_motion_right(t_win *term, t_cmline **cm)
{
	(*cm)->cur_pos_term = ((*cm)->cur_pos_term == (term->win_column - 1) ? 0 :
		(*cm)->cur_pos_term + 1);
	(*cm)->cur_pos_x = ((*cm)->cur_pos_term == 0 ? 0 : (*cm)->cur_pos_x + 1);
	(*cm)->cur_pos_y = ((*cm)->cur_pos_term == 0 ?
		(*cm)->cur_pos_y + 1 : (*cm)->cur_pos_y);
	(*cm)->cur_pos_y_tocm = ((*cm)->cur_pos_term == 0 ?
		(*cm)->cur_pos_y_tocm + 1 : (*cm)->cur_pos_y_tocm);
	(*cm)->cur_pos_line = (*cm)->cur_pos_line + 1;
	(*cm)->cur_pos_cm = (*cm)->cur_pos_cm + 1;
	(*cm)->ch_after_cur = (*cm)->ch_after_cur - 1;
	(*cm)->cur = get_current_key(&(*cm)->line, (*cm)->cur_pos_line - 1);
}

void			conf_motion_left(t_win *term, t_cmline **cm)
{
	int			len_pos_x;

	len_pos_x = (*cm)->cur_pos_y != 1 ? term->win_column - 1 :
		(term->win_column - 1) - (*cm)->prompt_len;
	(*cm)->cur_pos_term = ((*cm)->cur_pos_term == 0 ? (term->win_column - 1) :
		(*cm)->cur_pos_term - 1);
	(*cm)->cur_pos_x = ((*cm)->cur_pos_term == (term->win_column - 1) ?
		len_pos_x : (*cm)->cur_pos_x - 1);
	(*cm)->cur_pos_y = ((*cm)->cur_pos_term == (term->win_column - 1) ?
		(*cm)->cur_pos_y - 1 : (*cm)->cur_pos_y);
	(*cm)->cur_pos_y_tocm = ((*cm)->cur_pos_term == (term->win_column - 1) ?
		(*cm)->cur_pos_y_tocm - 1 : (*cm)->cur_pos_y_tocm);
	(*cm)->cur_pos_line = (*cm)->cur_pos_line - 1;
	(*cm)->cur_pos_cm = (*cm)->cur_pos_cm - 1;
	(*cm)->ch_after_cur = (*cm)->ch_after_cur + 1;
	(*cm)->cur = get_current_key(&(*cm)->line, (*cm)->cur_pos_line - 1);
}

void			conf_delete(t_win *term, t_cmline **cm)
{
	int			len_pos_x;
	int			nb;

	nb = (*cm)->nb_line_toline;
	len_pos_x = (*cm)->cur_pos_y != 1 ? term->win_column - 1 :
		(term->win_column - 1) - (*cm)->prompt_len;
	(*cm)->cur_pos_term = (*cm)->cur_pos_term == 0 ? (term->win_column - 1) :
		(*cm)->cur_pos_term - 1;
	(*cm)->cur_pos_x = ((*cm)->cur_pos_term == (term->win_column - 1) ?
		len_pos_x : (*cm)->cur_pos_x - 1);
	(*cm)->cur_pos_y = ((*cm)->cur_pos_term == (term->win_column - 1) ?
		(*cm)->cur_pos_y - 1 : (*cm)->cur_pos_y);
	(*cm)->cur_pos_y_tocm = ((*cm)->cur_pos_term == (term->win_column - 1) ?
		(*cm)->cur_pos_y_tocm - 1 : (*cm)->cur_pos_y_tocm);
	(*cm)->cur_pos_line = (*cm)->cur_pos_line - 1;
	(*cm)->cur_pos_cm = (*cm)->cur_pos_cm - 1;
	--(*cm)->line_len;
	(*cm)->nb_line_toline = (*cm)->line_len / ((term->win_column - 1) -
		(*cm)->prompt_len);
	(*cm)->nb_line_tocm -= nb == (*cm)->nb_line_toline ? 0 : 1;
	(*cm)->cur = get_current_key(&(*cm)->line, (*cm)->cur_pos_line - 1);
}
