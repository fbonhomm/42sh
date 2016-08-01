/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_doublequote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:33:18 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/04 19:13:13 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

char				*handle_backslash(char *str, int *i)
{
	char			*tmp;
	int				j;
	int				len;

	len = ft_strlen(str);
	j = 0;
	tmp = malloc(sizeof(char) * len);
	if (!tmp)
		return (NULL);
	ft_bzero(tmp, ft_strlen(str));
	while (j < (*i))
	{
		tmp[j] = str[j];
		j++;
	}
	j++;
	while (j < len)
	{
		tmp[j - 1] = str[j];
		j++;
	}
	*i += 1;
	return (tmp);
}

char				*handle_dollar(char *str, int *i)
{
	char			*tmp;
	char			*tmp2;

	if (str[*i + 1] == ' ' || str[*i + 1] == '\t' || str[*i + 1] == '\0')
	{
		*i += 1;
		return (str);
	}
	tmp = ft_strsub(str, 0, *i);
	tmp2 = replace_dollar(&str[*i], i);
	if (tmp2)
	{
		str = ft_strjoin(tmp, tmp2);
		ft_strdel(&tmp2);
	}
	else
		str = ft_strdup(tmp);
	ft_strdel(&tmp);
	return (str);
}

char				*backquote_good(char *str, int *i, int len)
{
	char			*before;
	char			*to_convert;
	char			*after;
	char			*all;

	before = ft_strsub(str, 0, *i);
	to_convert = ft_strsub(str, *i, len + 2);
	after = ft_strsub(str, *i + len + 2, ft_strlen(str));
	if ((all = format_backquote(to_convert)) == NULL)
		return (NULL);
	*i += ft_strlen(all);
	ft_strdel(&to_convert);
	to_convert = ft_strjoin(before, all);
	ft_strdel(&before);
	ft_strdel(&all);
	all = ft_strjoin(to_convert, after);
	ft_strdel(&after);
	ft_strdel(&to_convert);
	return (all);
}

char				*handle_backquote(char *str, int *i)
{
	int				len;
	int				j;

	j = 0;
	len = 0;
	while (str[j])
	{
		if (str[j] == '`')
		{
			j++;
			while (str[j] && str[j] != '`' && str[j] != '\"')
			{
				len++;
				j++;
			}
			return (backquote_good(str, i, len));
		}
		else
			j++;
	}
	return (NULL);
}

char				*format_doublequote(char *str2, int quote)
{
	int				type;
	char			*tmp;
	char			*str;
	int				test;

	test = 1;
	str = ft_strdup(str2);
	type = 0;
	str = handle_comp(str, &type, test);
	if (!str)
		return (NULL);
	if (quote)
	{
		if (ft_strlen(str) < 2)
			return (str);
		str = ft_memmove(str, str + 1, ft_strlen(str) - 2);
		str[ft_strlen(str) - 2] = '\0';
	}
	if (!type)
	{
		tmp = ft_strdup(str);
		ft_strdel(&str);
		str = tmp;
	}
	return (str);
}
