/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:35:31 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 17:35:32 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

char		**get_args(char **arg_list)
{
	int		i;

	if (arg_list == NULL)
		return (NULL);
	i = 0;
	while (arg_list[i])
	{
		if (arg_list[i][0] != '-' || (arg_list[i][0] == '-' &&
		arg_list[i][1] == 0) || (arg_list[i][0] == '-' &&
		arg_list[i][1] == '-'))
			break ;
		++i;
	}
	if (arg_list[i] && arg_list[i][0] == '-' && arg_list[i][1] == '-')
		++i;
	return (&arg_list[i]);
}

char		*get_options(char **args)
{
	int		i;
	char	*options;
	char	*tmp;

	options = NULL;
	i = 0;
	while (args[i] != NULL)
	{
		if (args[i][0] == '-' && args[i][1] != 0 && args[i][1] != '-')
		{
			tmp = options;
			options = options == NULL ? ft_strdup(args[i]) :
										ft_strjoin(options, args[i]);
			ft_strdel(&tmp);
			if (options == NULL)
			{
				g_error = EALLOC;
				return (NULL);
			}
		}
		else
			break ;
		++i;
	}
	return (options);
}

char		parser_opt(char *opts, char *opt)
{
	int		i;

	i = 0;
	if (opts == NULL)
		return (0);
	while (opts[i] != '\0')
	{
		if (opts[i] == '-')
		{
			while (opts[i] == '-')
				i++;
			while (opts[i] != '\0' && opts[i] != ' ')
			{
				if (ft_strchr(opt, opts[i]) == NULL)
					return (opts[i]);
				i++;
			}
		}
		else if (opts[i] == ' ')
			i++;
		else
			return (opts[i]);
	}
	return (0);
}
