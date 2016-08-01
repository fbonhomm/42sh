/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo_edit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriot <eduriot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:32:00 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/06 14:19:12 by eduriot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int					backslash_echo_check(char *str)
{
	int				i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			return (1);
		i++;
	}
	return (0);
}

char				*delete_str(char *str, int i, int modify)
{
	int				j;

	j = 0;
	while (j < i)
		j++;
	while (str[i])
	{
		str[j] = str[i + modify];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char				*replace_str(char *str, int i, char c, int modify)
{
	int				j;

	j = 0;
	while (j <= i)
		j++;
	if (c)
		str[i] = c;
	else
		j--;
	while (str[i + modify])
	{
		str[j] = str[i + modify];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

void				handle_moins_n(char **cmd_list, int *i, int *new_line)
{
	if (cmd_list[*i] && ft_strequ(cmd_list[*i], "-n"))
	{
		*new_line = 0;
		*i += 1;
	}
}
