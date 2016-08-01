/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:36:23 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/04 19:12:50 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

int				is_quote(char c)
{
	return ((c == '\'' || c == '\"' || c == '`'));
}

int				is_blank(char c)
{
	return ((c == ' ' || c == '\t' || c == '\n'));
}

int				is_operator(char c)
{
	return ((c == '|' || c == '&' || c == '>' || c == '<' || c == ';'));
}
