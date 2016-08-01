/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_conf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:34:14 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:34:15 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

void			conf_history(t_win *term, t_cmline **cm)
{
	UNUSED(term);
	(*cm)->cur_pos_y_tocm += (*cm)->prev->cur_pos_y_tocm + 1;
	(*cm)->nb_line_tocm += (*cm)->prev->nb_line_tocm + 1;
	(*cm)->cur_pos_cm = (*cm)->prev->cur_pos_cm;
	(*cm)->cur_pos_y = 0;
	(*cm)->cur_pos_x = 0;
	(*cm)->ch_after_cur = -1;
	(*cm)->line_len = 0;
}

void			conf_del_print(t_win *term, t_cmline **cm)
{
	(*cm)->cur_pos_term = ((*cm)->cur_pos_term == (term->win_column - 1) ? 0 :
		(*cm)->cur_pos_term + 1);
	(*cm)->cur_pos_x = (*cm)->cur_pos_term ? (*cm)->cur_pos_x + 1 : 0;
	(*cm)->cur_pos_y += (*cm)->cur_pos_term == 0;
	(*cm)->cur_pos_y_tocm += (*cm)->cur_pos_term == 0;
	++(*cm)->cur_pos_line;
	++(*cm)->cur_pos_cm;
	(*cm)->cur = get_current_key(&(*cm)->line, (*cm)->cur_pos_line - 1);
}

void			conf_print(t_win *term, t_cmline **cm)
{
	(*cm)->cur_pos_term = ((*cm)->cur_pos_term == (term->win_column - 1) ? 0 :
		(*cm)->cur_pos_term + 1);
	(*cm)->cur_pos_x = (*cm)->cur_pos_term ? (*cm)->cur_pos_x + 1 : 0;
	(*cm)->cur_pos_y += (*cm)->cur_pos_term == 0;
	(*cm)->cur_pos_y_tocm += (*cm)->cur_pos_term == 0;
	++(*cm)->cur_pos_line;
	++(*cm)->cur_pos_cm;
	++(*cm)->line_len;
	(*cm)->nb_line_toline += (((*cm)->line_len + (*cm)->prompt_len) %
		(term->win_column) == 0 && (*cm)->line_len);
	(*cm)->nb_line_tocm += (((*cm)->line_len + (*cm)->prompt_len) %
		(term->win_column) == 0 && (*cm)->line_len);
	(*cm)->cur = get_current_key(&(*cm)->line, (*cm)->cur_pos_line - 1);
}
