/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:34:54 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/02 14:55:29 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int				print_history_line(t_win *term, t_line *line)
{
	int			nb_ch;

	nb_ch = 0;
	while (line != NULL)
	{
		print_character(term, line->ch);
		line = line->next;
		nb_ch++;
	}
	return (nb_ch);
}

void			print_all_line(t_win *term, t_cmline *cm)
{
	t_line		*line;

	line = cm->cur ? cm->cur->next : NULL;
	if (line == NULL && cm->cur != NULL)
	{
		cm = cm->next;
		line = cm->line;
		ft_putchar_fd('\n', STDIN_FILENO);
	}
	while (42)
	{
		print_line(term, line, cm->cur_pos_term);
		if (cm->next == NULL)
			break ;
		ft_putchar_fd('\n', STDIN_FILENO);
		cm = cm->next;
		line = cm->line;
	}
}

void			print_line(t_win *term, t_line *line, int co)
{
	while (line != NULL)
	{
		co = co == (term->win_column - 1) ? 0 : ++co;
		print_key(co, line->ch);
		line = line->next;
	}
}

void			print_key(int position, int key)
{
	ft_putchar_fd(key, STDIN_FILENO);
	if (position == 0)
		cur_motion_handler(DOWN, 1);
}

int				print_add_character(t_win *term, int key)
{
	t_cmline	*tmp;
	int			nb_line;

	if (term->all_act->nb_ch >= 4096)
		return (0);
	term->all_act->nb_ch++;
	tmp = term->all_act->cm;
	nb_line = tmp->nb_line_tocm;
	add_key(key, &term->all_act->cm->line, term->all_act->cm->cur_pos_line);
	print_character(term, key);
	if (nb_line != tmp->nb_line_tocm)
		new_data_for_end(&tmp);
	if (term->all_act->cm->ch_after_cur > -1 || term->all_act->cm->next)
	{
		tputs(tgetstr("cd", NULL), 1, shput);
		print_all_line(term, tmp);
		cur_motion_handler(LEFT, term->win_column);
		cur_motion_handler(UP, tmp->nb_line_tocm - tmp->cur_pos_y_tocm);
		cur_motion_handler(RIGHT, tmp->cur_pos_term);
	}
	return (1);
}
