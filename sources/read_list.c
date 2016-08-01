/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 14:48:38 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/02 14:56:29 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

void			init_history(t_cmline **history)
{
	while (42)
	{
		(*history)->nb_line_tocm = 0;
		(*history)->ch_after_cur = -1;
		(*history)->line_len = 0;
		(*history)->cur_pos_y_tocm = 0;
		if ((*history)->next == NULL)
			break ;
		(*history) = (*history)->next;
	}
	while ((*history)->prev != NULL)
		*history = (*history)->prev;
}

t_line			*init_line(char ch)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (line == NULL)
	{
		g_error = EALLOC;
		return (NULL);
	}
	line->next = NULL;
	line->prev = NULL;
	line->ch = ch;
	return (line);
}

t_all			*init_allcm(void)
{
	t_all		*new;

	new = (t_all *)malloc(sizeof(t_all));
	if (new == NULL)
	{
		g_error = EALLOC;
		return (NULL);
	}
	new->nb_ch = 0;
	new->next = NULL;
	new->prev = NULL;
	new->cm = NULL;
	return (new);
}

t_cmline		*init_cmline(void)
{
	t_cmline	*cm;

	cm = (t_cmline *)malloc(sizeof(t_cmline));
	if (cm == NULL)
	{
		g_error = EALLOC;
		return (NULL);
	}
	cm->prev = NULL;
	cm->next = NULL;
	cm->line = NULL;
	cm->cur = NULL;
	cm->prompt_name = NULL;
	cm->prompt_len = 0;
	cm->cur_pos_x = 0;
	cm->cur_pos_y = 0;
	cm->cur_pos_y_tocm = 0;
	cm->line_len = 0;
	cm->cur_pos_term = 0;
	cm->cur_pos_line = 0;
	cm->cur_pos_cm = 0;
	cm->nb_line_toline = 0;
	cm->nb_line_tocm = 0;
	cm->ch_after_cur = -1;
	return (cm);
}

void			free_line(t_line **line)
{
	t_line		*tmp;

	while (*line != NULL)
	{
		tmp = *line;
		*line = (*line)->next;
		free_key(&tmp);
	}
}
