/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 19:33:18 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/14 17:43:01 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int					new_cmline_for_read(t_cmline **cm, int dir)
{
	if ((dir == LEFT && !(*cm)->prev) || (dir == RIGHT && !(*cm)->next))
		return (-1);
	(*cm) = dir == LEFT ? (*cm)->prev : (*cm)->next;
	return (0);
}

void				new_data_for_end(t_cmline **cm)
{
	t_cmline		*tmp;

	tmp = *cm;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (42)
	{
		if (tmp->prev && tmp->prev->nb_line_tocm < tmp->nb_line_tocm)
			tmp->prev->nb_line_tocm = tmp->nb_line_tocm;
		else if (tmp->prev && tmp->prev->nb_line_tocm > tmp->nb_line_tocm)
		{
			tmp->nb_line_tocm = tmp->prev->nb_line_tocm;
			new_data_for_end(cm);
		}
		else
			break ;
		tmp = tmp->prev;
	}
}

void				new_prompt_for_relaunch(t_win *term, t_cmline **cm)
{
	char			*name;

	if (term->quote == (DQUOTE | BQUOTE))
		name = "bquote dquote> ";
	else if (term->quote == DQUOTE)
		name = "dquote> ";
	else if (term->quote == QUOTE)
		name = "quote> ";
	else if (term->quote == BQUOTE)
		name = "bquote> ";
	else if (term->quote == CURSH)
		name = "cursh> ";
	else if (term->quote == SUBSH)
		name = "SUBSH> ";
	else if (term->quote == CROSH)
		name = "CROSH> ";
	else
		name = "";
	(*cm)->prompt_name = name;
	(*cm)->prompt_len = ft_strlen((*cm)->prompt_name);
	(*cm)->cur_pos_term = (*cm)->prompt_len;
}

void				new_prompt_for_initialize(t_cmline *cm, t_cmline **new)
{
	char			*name;

	if (cm != NULL && cm->prompt_name != NULL
		&& ft_strcmp(cm->prompt_name, "42sh> ") != 0)
		name = "";
	else
		name = "42sh> ";
	(*new)->prompt_name = name;
	(*new)->prompt_len = ft_strlen(name);
	(*new)->cur_pos_term = (*new)->prompt_len;
	(*new)->cur_pos_term = (*new)->prompt_len;
}
