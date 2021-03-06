/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_ctrl2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 17:08:45 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/14 17:42:46 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int			kill_read(t_win *term, int key)
{
	UNUSED(key);
	if (term->all_act->cm->line != NULL)
		return (1);
	unset_attr();
	free_brain(S_ALL);
	write(STDOUT_FILENO, "\n", 1);
	exit(0);
	return (0);
}

int			reset_cmd(t_win *term, int key)
{
	cur_motion_home(term, key);
	tputs(tgetstr("cd", NULL), 1, shput);
	free_cmline(&term->all_act->cm);
	term->all_act->cm = init_cmline();
	new_prompt_for_initialize(term->all_act->cm, &term->all_act->cm);
	ft_putendl_fd("", STDIN_FILENO);
	ft_putstr_fd("42sh> ", STDIN_FILENO);
	return (0);
}
