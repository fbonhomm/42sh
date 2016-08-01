/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 17:36:59 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/04 19:12:54 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_H
# define MEMORY_H

# define S_WIN 1
# define S_PARSER 2
# define S_HASH 3
# define S_ALL 4

void				*g_memory(int type, int size);
void				f_memory(void);

#endif
