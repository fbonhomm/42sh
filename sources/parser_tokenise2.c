/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tokenise2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:34:04 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:34:05 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static char	*g_ope[12] = {
	">",
	">>",
	"<",
	"<<",
	">&",
	"<&",
	"<>",
	"|",
	"||",
	"&&",
	";",
	"&",
};

t_subtok		add_operator(char *operator)
{
	int			i;

	i = 0;
	while (i < AMPERSAND + 1)
	{
		if (ft_strcmp(g_ope[i], operator) == 0)
		{
			return (i);
		}
		++i;
	}
	return (i);
}

char			*cmp_operand(char *operand)
{
	int			i;

	i = 0;
	if (operand[1] != '\0' && operand[2] != '\0')
		return (&operand[2]);
	while (i < AMPERSAND + 1)
	{
		if (ft_strncmp(operand, g_ope[i], 2) == 0 && ft_strlen(operand) < 3)
			return (NULL);
		++i;
	}
	return (&operand[1]);
}
