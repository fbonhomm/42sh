/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_backquote_dollar.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:33:00 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/04 19:19:32 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static int			strstr_begin(char *str1, char *str2)
{
	int				i;

	i = 0;
	while (str1[i] == str2[i])
		i++;
	if (str1[i] == '\0' && str2[i] == '=')
		return (1);
	return (0);
}

static char			*clean_str(char *s, int ln, int j, int *i)
{
	ln = 0;
	while (ln < j - 2)
	{
		*i += 1;
		ln++;
	}
	return (s);
}

static int			find_env_and_replace(int *j, char **s, int ln)
{
	char			*tmp;
	char			*tmp2;
	char			*rest;

	tmp = ft_strsub(*s, 1, ln - 1);
	rest = ft_strsub(*s, ln, ft_strlen(*s));
	if ((search_in_local(&tmp, &rest, s)))
		return (1);
	while (g_env[*j])
	{
		if (strstr_begin(tmp, g_env[*j]))
		{
			tmp2 = ft_strchr(g_env[*j], '=');
			*j = ft_strlen(tmp2);
			*s = ft_strjoin(tmp2 + 1, rest);
			ft_strdel(&tmp);
			ft_strdel(&rest);
			return (1);
		}
		*j += 1;
	}
	if (tmp)
		ft_strdel(&tmp);
	if (rest)
		ft_strdel(&rest);
	return (0);
}

static char			*handle_return_value(char *str)
{
	char			*rest;
	char			*str2;
	char			*all;

	rest = ft_strsub(str, 2, ft_strlen(str));
	str2 = ft_itoa(last_ret(0, 1));
	all = ft_strjoin(str2, rest);
	ft_strdel(&rest);
	ft_strdel(&str2);
	return (all);
}

char				*replace_dollar(char *s, int *i)
{
	int				ln;
	char			*rest;
	int				j;
	int				is;

	j = 0;
	ln = 1;
	if (s[ln] == '?')
		return (handle_return_value(s));
	else
	{
		while (s[ln] && s[ln] != 32 && s[ln] != '$' && s[ln] != 34 &&
			s[ln] != '\\')
			ln++;
		rest = ft_strsub(s, ln, ft_strlen(s));
		is = find_env_and_replace(&j, &s, ln);
		if (!is)
			return (rest);
		if (rest)
			ft_strdel(&rest);
	}
	return (clean_str(s, ln, j, i));
}
