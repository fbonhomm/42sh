/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduriot <eduriot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:32:07 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/15 10:25:21 by eduriot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static int			convert_tmp_into_decimal(char *str)
{
	int				i;
	int				j;
	int				buf;

	i = 0;
	j = 0;
	buf = 0;
	while (str[i])
		i++;
	i--;
	while (str[j])
	{
		buf = buf + ((str[j] - 48) * ft_pow(8, i));
		j++;
		i--;
	}
	return (buf);
}

static char			*handle_octal_convertion(char *str, char *strbase, int i)
{
	int				char_conv;
	int				j;
	int				var;
	char			*tmp;

	j = 0;
	var = 0;
	char_conv = 0;
	while (str[j] && j < 3 && ft_isdigit(str[j]))
	{
		if (!var && str[j] >= '1' && str[j] <= '7')
		{
			char_conv = char_conv * 10 + str[j] - 48;
			var += 1;
		}
		else if (str[j] >= '0' && str[j] <= '7' && var)
			char_conv = char_conv * 10 + str[j] - 48;
		else if (str[j] > '7')
			break ;
		j++;
	}
	tmp = ft_strsub(str, 0, j);
	char_conv = convert_tmp_into_decimal(tmp);
	strbase = replace_str(strbase, i, (char)char_conv, (2 + j));
	return (strbase);
}

static char			*backslash_echo_next(char *str, int i)
{
	if (str[i + 1] == 'f')
		str = replace_str(str, i, 12, 2);
	else if (str[i + 1] == 'n')
		str = replace_str(str, i, 10, 2);
	else if (str[i + 1] == 'r')
		str = replace_str(str, i, 13, 2);
	else if (str[i + 1] == 't')
		str = replace_str(str, i, 9, 2);
	else if (str[i + 1] == 'v')
		str = replace_str(str, i, 11, 2);
	else if (str[i + 1] == '\\')
		str = replace_str(str, i, 92, 2);
	else if (str[i + 1] == '0' && str[i + 2])
		str = handle_octal_convertion(&str[i + 2], str, i);
	return (str);
}

static char			*backslash_echo(char *str, int *new_line, int *stop, int i)
{
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1])
		{
			if (str[i + 1] == 'a')
			{
				ft_putchar_fd(7, STDOUT_FILENO);
				str = delete_str(str, i, 2);
			}
			else if (str[i + 1] == 'b')
				str = delete_str(str, i - 1, 3);
			else if (str[i + 1] == 'c')
			{
				str[i] = '\0';
				*new_line = 0;
				*stop = 1;
			}
			else
				str = backslash_echo_next(str, i);
		}
		i++;
	}
	return (str);
}

int					builtin_echo(char **cmd_list)
{
	int				new_line;
	int				i;
	int				stop;
	int				j;

	j = 0;
	stop = 0;
	i = 0;
	new_line = 1;
	handle_moins_n(cmd_list, &i, &new_line);
	while (cmd_list[i] && stop == 0)
	{
		if (backslash_echo_check(cmd_list[i]))
			ft_putstr_fd(backslash_echo(cmd_list[i], &new_line, &stop, j), 1);
		else
			ft_putstr_fd(cmd_list[i], STDOUT_FILENO);
		if (cmd_list[i + 1] && stop == 0)
			ft_putchar(' ');
		i++;
	}
	if (new_line)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
