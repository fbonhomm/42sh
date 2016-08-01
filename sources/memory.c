/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:32:54 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/04 19:19:00 by killian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

void				*g_memory(int type, int size)
{
	static t_win	term;
	static t_hash	**hash;
	static t_parser	parser;

	if (size == -1 && type == S_HASH)
		hash = NULL;
	if (type == S_PARSER)
		return (&parser);
	if (type == S_WIN)
		return (&term);
	if (type == S_HASH)
	{
		if (hash == NULL && size > 0
			&& (hash = (t_hash **)malloc(size)) == NULL)
		{
			g_error = EALLOC;
			return (NULL);
		}
		return (hash);
	}
	return (NULL);
}
