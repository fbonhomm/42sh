/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 18:57:39 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/02 11:42:15 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

t_cmline		*add_cmline(t_cmline *cm, t_line *line)
{
	t_cmline	*new;

	new = init_cmline();
	if (new == NULL)
	{
		g_error = EALLOC;
		return (NULL);
	}
	if (cm == NULL)
	{
		new->line = cp_all_line(line);
		return (new);
	}
	while (cm->next != NULL)
		cm = cm->next;
	cm->next = new;
	new->prev = cm;
	if (line != NULL)
		new->line = cp_all_line(line);
	else
		new->line = NULL;
	return (new);
}

void			add_allcm(t_all **allcm, t_cmline *cm)
{
	t_all		*new;

	new = init_allcm();
	new->cm = cp_all_cmline(cm);
	(*allcm)->prev = new;
	new->next = (*allcm);
	*allcm = (*allcm)->prev;
}

void			add_key2(t_line *new, t_line **line, t_line *prev, t_line *tmp)
{
	if (prev == NULL)
	{
		new->next = *line;
		new->next->prev = new;
		*line = new;
		return ;
	}
	if (tmp == NULL)
	{
		new->prev = prev;
		prev->next = new;
		return ;
	}
	prev->next = new;
	new->next = tmp;
	new->prev = prev;
	tmp->prev = new;
}

void			add_key(int key, t_line **line, int pos)
{
	t_line		*new;
	t_line		*tmp;
	t_line		*prev;

	new = init_line(key);
	tmp = *line;
	prev = NULL;
	if (*line == NULL)
	{
		*line = new;
		return ;
	}
	while (tmp != NULL && pos > 0)
	{
		prev = tmp;
		tmp = tmp->next;
		--pos;
	}
	add_key2(new, line, prev, tmp);
}
