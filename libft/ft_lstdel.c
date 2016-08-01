/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:35:07 by ksoulard          #+#    #+#             */
/*   Updated: 2015/11/27 18:43:30 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*tmp;

	if (alst && del && *alst)
	{
		while (*alst)
		{
			tmp = *alst;
			ft_lstdelone(&(*alst), del);
			*alst = tmp->next;
		}
	}
}
