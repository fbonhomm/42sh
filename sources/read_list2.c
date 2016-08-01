/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:34:27 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/02 11:42:26 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

void			cp_allcm(t_all **root_allcm, t_all *allcm)
{
	t_all		*new;
	t_all		*tmp;

	new = init_allcm();
	new->cm = cp_all_cmline(allcm->cm);
	tmp = *root_allcm;
	if (tmp == NULL)
		*root_allcm = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

void			cp_cmline(t_cmline **root_cmline, t_cmline *cm)
{
	t_cmline	*tmp;
	t_cmline	*new;

	new = init_cmline();
	new->line = cp_all_line(cm->line);
	new_prompt_for_initialize(cm, &new);
	tmp = *root_cmline;
	if (tmp == NULL)
		*root_cmline = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

t_line			*cp_all_line(t_line *line)
{
	t_line		*new;
	int			i;

	i = 0;
	new = NULL;
	while (line != NULL)
	{
		add_key(line->ch, &new, i);
		i++;
		line = line->next;
	}
	return (new);
}

t_cmline		*cp_all_cmline(t_cmline *cm)
{
	t_cmline	*new;

	new = NULL;
	if (cm == NULL)
		return (NULL);
	while (cm->prev != NULL)
		cm = cm->prev;
	while (cm != NULL)
	{
		cp_cmline(&new, cm);
		cm = cm->next;
	}
	return (new);
}

t_all			*cp_all_allcm(t_all *allcm, t_cmline *cm)
{
	t_all		*new;

	new = NULL;
	new = init_allcm();
	new->cm = cm;
	if (allcm == NULL)
		return (new);
	while (allcm->prev != NULL)
		allcm = allcm->prev;
	while (allcm != NULL)
	{
		cp_allcm(&new, allcm);
		allcm = allcm->next;
	}
	return (new);
}
