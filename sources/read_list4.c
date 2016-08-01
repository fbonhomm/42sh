/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:34:35 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:34:36 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

void			free_key(t_line **line)
{
	(*line)->ch = 0;
	free(*line);
	*line = NULL;
}

void			delete_left_key(t_line **line, int pos)
{
	t_line		*prev;
	t_line		*tmp;

	tmp = *line;
	prev = NULL;
	while (tmp->next != NULL && pos > 0)
	{
		prev = tmp;
		tmp = tmp->next;
		--pos;
	}
	if (prev == NULL)
	{
		*line = tmp->next;
		return (free_key(&tmp));
	}
	if (pos > 0 || tmp->next == NULL)
	{
		tmp->prev->next = NULL;
		return (free_key(&tmp));
	}
	prev->next = tmp->next;
	tmp->next->prev = prev;
	return (free_key(&tmp));
}

t_line			*get_current_key(t_line **line, int pos)
{
	t_line		*tmp;

	tmp = *line;
	if (tmp == NULL)
		return (NULL);
	while (tmp->next && pos > 0)
	{
		tmp = tmp->next;
		pos--;
	}
	return (tmp);
}

void			free_cmline(t_cmline **cm)
{
	t_cmline	*tmp;

	while (*cm != NULL)
	{
		tmp = *cm;
		*cm = (*cm)->next;
		free_line(&tmp->line);
		free(tmp);
		tmp = NULL;
	}
	*cm = NULL;
}

void			free_allcm(t_all **allcm)
{
	t_all		*tmp;

	while ((*allcm)->prev != NULL)
		*allcm = (*allcm)->prev;
	tmp = *allcm;
	while (*allcm != NULL)
	{
		tmp = *allcm;
		*allcm = (*allcm)->next;
		free_cmline(&tmp->cm);
		free(tmp);
		tmp = NULL;
	}
}
