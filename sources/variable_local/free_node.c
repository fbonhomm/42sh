/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/15 23:09:01 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/16 14:12:59 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

t_var			*free_node_var(t_var *v, t_var *v1, t_var *tmp)
{
	tmp = v;
	ft_free(&v1->key);
	ft_free(&v1->value);
	free(v1);
	return (tmp);
}

t_funct			*free_node_funct(t_funct *f, t_funct *f1, t_funct *tmp)
{
	tmp = f;
	ft_free(&f1->key);
	ft_free_array(&f1->content);
	free(f1);
	return (tmp);
}
