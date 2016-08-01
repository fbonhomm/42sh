/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_job.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:03:31 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/19 12:19:47 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "job.h"

void			print_done_job(t_job *j)
{
	ft_putchar('[');
	ft_putnbr(j->id);
	ft_putstr("] ");
	ft_putnbr(j->pid);
	ft_putstr(" Done ");
	ft_put_array(j->command, " ");
	ft_putchar('\n');
}

void			print_job(t_job *j)
{
	ft_putchar('[');
	ft_putnbr(j->id);
	ft_putstr("] ");
	ft_putnbr(j->pid);
	ft_putchar(' ');
	ft_put_array(j->command, " ");
	ft_putchar('\n');
}
