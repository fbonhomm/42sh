/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 16:24:28 by ksoulard          #+#    #+#             */
/*   Updated: 2016/07/25 14:59:31 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static struct s_readf	ctrl[] = {
	{UP, cur_motion_up},
	{DOWN, cur_motion_down},
	{LEFT, cur_motion_left},
	{RIGHT, cur_motion_right},
	{HOME, cur_motion_home},
	{END, cur_motion_end},
	{ALTUP, cur_motion_altup},
	{ALTDOWN, cur_motion_altdown},
	{ENTER, end_or_relaunch},
	{DELETE, del_character},
	{CTRLK, cut_right_line},
	{CTRLU, cut_left_line},
	{CTRLL, copy_right_line},
	{CTRLI, copy_left_line},
	{CTRLP, paste_line},
	{CTRLF, cur_motion_forward},
	{CTRLB, cur_motion_backward},
	{CTRLD, kill_read},
	{CTRLC, reset_cmd},
};

static int			(*key_handler(int key))(t_win *, int)
{
	int				i;

	i = 0;
	if (key >= 0x20 && key <= 0x7e)
		return (print_add_character);
	while (i < 19)
	{
		if (ctrl[i].value == (unsigned int)key)
			return (ctrl[i].key_controler);
		i++;
	}
	return (NULL);
}

int					read_handler(t_win *term, int key)
{
	int				(*key_controler)(t_win *, int);
	int				ret;

	if (g_error != NULL)
	{
		if (g_error != ESIGWINCH)
			return (-1);
		free_allcm(&term->all_act);
		if (initialize_read(term) == -1)
			return (-1);
		g_error = NULL;
		return (0);
	}
	key_controler = key_handler(key);
	if (key_controler == NULL)
		return (EXIT_FAILURE);
	ret = (*key_controler)(term, key);
	return (ret);
}
