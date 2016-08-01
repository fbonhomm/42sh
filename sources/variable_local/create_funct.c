/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:10:30 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/08/16 13:41:37 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

char			**g_content;

int				verif_first_acc(char *tmp)
{
	if (!ft_strcmp(tmp, "{"))
		return (1);
	else
	{
		ft_free_array(&g_content);
		ft_putstr_fd("funct: syntax error\n", 2);
		return (0);
	}
}

int				verif_second_acc(char *tmp)
{
	if (!ft_strcmp(tmp, "}"))
	{
		if ((!(g_content)) || (!(g_content[0])))
		{
			ft_free_array(&g_content);
			ft_putstr_fd("funct: syntax error\n", 2);
			return (0);
		}
		else
			return (0);
	}
	return (1);
}

void			add_content(char **tmp, int i)
{
	g_content[i] = ft_str_one_space(*tmp);
	g_content[i + 1] = NULL;
	ft_free(tmp);
}

void			loop_set_funct(void)
{
	int			i[2];
	char		*tmp;

	i[0] = 0;
	i[1] = 0;
	while (42)
	{
		ft_putstr("funct > ");
		if ((get_next_line(STDIN_FILENO, &tmp)) < 0)
		{
			ft_free(&tmp);
			ft_free_array(&g_content);
			ft_putstr_fd("funct: get_next_line error\n", 2);
			break ;
		}
		if ((i[0] == 0) && (!(verif_first_acc(tmp))))
			break ;
		if (i[0])
		{
			if (!(verif_second_acc(tmp)))
				break ;
			add_content(&tmp, i[1]++);
		}
		i[0]++;
	}
}

int				create_funct(char *cmd)
{
	char		*key;

	if (!conform_set_funct(cmd))
		return (-1);
	g_content = (char**)malloc(sizeof(char*) * 100);
	key = ft_strndup(cmd, (ft_strlen(cmd) - 2));
	loop_set_funct();
	if (g_content && g_content[0])
		add_node_funct(&g_tree->funct, key, g_content);
	ft_free(&key);
	ft_free_array(&g_content);
	return (0);
}
