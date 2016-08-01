/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:35:08 by ksoulard          #+#    #+#             */
/*   Updated: 2016/07/25 11:15:14 by eduriot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int					shput(int c)
{
	write(1, &c, STDOUT_FILENO);
	return (c);
}

int					relaunch_read(t_win *term)
{
	cur_motion_handler(DOWN, (term->all_act->cm->nb_line_tocm -
		term->all_act->cm->cur_pos_y_tocm) + 1);
	term->all_act->cm = add_cmline(term->all_act->cm, NULL);
	if (term->all_act->cm == NULL)
		return (-1);
	new_prompt_for_relaunch(term, &term->all_act->cm);
	ft_putstr_fd(term->all_act->cm->prompt_name, STDIN_FILENO);
	return (1);
}

int					initialize_read(t_win *term)
{
	term->quote = 0;
	term->all_act = cp_all_allcm(term->all_save, init_cmline());
	if (term->all_act == NULL)
		return (-1);
	new_prompt_for_initialize(NULL, &term->all_act->cm);
	ft_putstr_fd(term->all_act->cm->prompt_name, STDIN_FILENO);
	return (0);
}

int					end_of_read(t_win *term)
{
	cur_motion_handler(DOWN, (term->all_act->cm->nb_line_tocm -
		term->all_act->cm->cur_pos_y_tocm) + 1);
	while (term->all_act->cm->prev != NULL)
		term->all_act->cm = term->all_act->cm->prev;
	if (term->all_save == NULL)
	{
		term->all_save = init_allcm();
		term->all_save->cm = cp_all_cmline(term->all_act->cm);
	}
	else
		add_allcm(&term->all_save, term->all_act->cm);
	term->all_save->nb_ch = term->all_act->nb_ch;
	free_line(&term->copy);
	free_allcm(&term->all_act);
	return (ENDOF);
}

int					sh1_read(void)
{
	char			c[4];
	int				ret;
	int				key;
	t_win			*term;

	term = g_memory(S_WIN, 0);
	if (initialize_read(term) == -1 || test_caps() == -1)
		return (-1);
	while (42)
	{
		ft_bzero(c, 4);
		if ((ret = read(STDIN_FILENO, c, 4)) < 0)
			return (int_error(EUNKNOW));
		key = (c[3] << 24) + (c[2] << 16) + (c[1] << 8) + c[0];
		ret = read_handler(term, key);
		if (ret == -1)
			return (-1);
		if (ret == ENDOF)
			return (end_of_read(term) == -1 ? -1 : 0);
		if (ret == RELAUNCH)
			if (relaunch_read(term) == -1)
				return (-1);
	}
	return (0);
}
