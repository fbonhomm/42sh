/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:32:21 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/16 13:41:14 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static int	parser_exit(char **cmd_list)
{
	if (cmd_list[0] != NULL && cmd_list[1] != NULL)
	{
		g_error = EARGS;
		return (-1);
	}
	return (0);
}

int			builtin_exit(char **cmd_list)
{
	int		var;

	if (parser_exit(cmd_list) == -1)
	{
		error("exit");
		return (-1);
	}
	if (cmd_list[0])
		var = ft_atoi(cmd_list[0]) & 03377;
	else
		var = 0;
	free_brain(S_ALL);
	free_tree();
	exit(var);
}
