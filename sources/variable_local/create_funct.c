/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_funct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 18:10:30 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 22:56:59 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

char			**g_content;

int				verif_first_acc(void)
{
	if (((g_content)[0] && (!(g_content)[1]) &&
			((!ft_strcmp((g_content)[0], "{")))))
	{
		ft_free(&g_content[0]);
		return (1);
	}
	else
	{
		ft_free_array(&g_content);
		ft_putstr_fd("funct: syntax error\n", 2);
		return (0);
	}
}

int				verif_second_acc(int *i)
{
	if (((g_content)[*i] && ((ft_strcmp((g_content)[*i], "}") == 0))))
	{
		if ((!(g_content)) || (!(g_content[1])))
		{
			ft_free_array(&g_content);
			ft_putstr_fd("funct: syntax error\n", 2);
			return (0);
		}
		else
		{
			ft_free(&g_content[*i]);
			return (0);
		}
	}
	return (1);
}

void			add_content(char **tmp, int i)
{
	g_content[i] = ft_strepur(2, *tmp, ' ', '\t');
	g_content[i + 1] = NULL;
	ft_free(tmp);
	ft_putstr("funct > ");
}

void			loop_set_funct(void)
{
	int			i[2];
	char		*tmp;

	i[0] = 0;
	i[1] = 0;
	while (42)
	{
		if ((get_next_line(STDIN_FILENO, &tmp)) < 0)
		{
			ft_free(&tmp);
			ft_free_array(&g_content);
			ft_putstr_fd("funct: get_next_line error\n", 2);
			break ;
		}
		add_content(&tmp, i[1]);
		if ((i[0] == 0) && (!(verif_first_acc())))
			break ;
		else
		{
			if (!(verif_second_acc(&i[1])))
				break ;
			i[1]++;
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
	g_content[0] = NULL;
	ft_putstr("funct > ");
	key = ft_strndup(cmd, (ft_strlen(cmd) - 2));
	loop_set_funct();
	if (g_content && g_content[0])
		add_node_funct(&g_tree->funct, key, g_content);
	ft_free(&key);
	ft_free_array(&g_content);
	return (0);
}
