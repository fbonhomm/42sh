/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:36:12 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:36:12 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int						is_less(int tok)
{
	return ((tok == LESS || tok == DLESS || tok == LESSGREAT));
}

int						is_great(int tok)
{
	return ((tok == GREAT || tok == DGREAT || tok == GREATAND));
}

int						is_redir(int tok)
{
	return ((tok == GREAT || tok == DGREAT || tok == LESS || tok == DLESS
		|| tok == GREATAND || tok == LESSGREAT));
}

int						is_separ(int tok)
{
	return ((tok == PIPE || tok == OR_IF || tok == AND_IF || tok == SEMI
		|| tok == AMPERSAND));
}

int						last_ret(int ret, int read)
{
	static int			last_ret = 0;

	if (read == 0 && ret >= 0 && ret <= 255)
		last_ret = ret;
	else if (ret < 0 && read == 0)
		return (ret);
	else if (read == 1)
		return (last_ret);
	return (0);
}
