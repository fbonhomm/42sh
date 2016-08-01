/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 09:46:34 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/14 17:42:39 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <core.h>

static int		convert_cmd(char **cmd)
{
	t_line		*tmp;
	t_win		*term;
	t_cmline	*cm;
	int			i;

	i = 0;
	term = g_memory(S_WIN, 0);
	cm = term->all_save->cm;
	if (!(*cmd = (char *)ft_memalloc(sizeof(char) * 4097 + cm->nb_line_tocm)))
		return (int_error(EALLOC));
	while (cm != NULL)
	{
		tmp = cm->line;
		while (tmp != NULL)
		{
			(*cmd)[i++] = tmp->ch;
			tmp = tmp->next;
		}
		(*cmd)[i++] = '\n';
		cm = cm->next;
	}
	return (0);
}

int				main_core(void)
{
	char		*cmd;

	cmd = NULL;
	if (get_newenv(g_env) == -1)
		return (EXIT_FAILURE);
	if (set_attr() == -1)
		return (EXIT_FAILURE);
	if (sh1_read() == -1)
		return (EXIT_FAILURE);
	if (unset_attr() == -1)
		return (EXIT_FAILURE);
	if (convert_cmd(&cmd) == -1)
		return (EXIT_FAILURE);
	if (parser(cmd) == -1)
		return (EXIT_FAILURE);
	ft_strdel(&cmd);
	free_brain(S_PARSER);
	if (g_error)
		g_error = NULL;
	return (EXIT_SUCCESS);
}

static int		init_env(void)
{
	char		*shlvl;
	int			lvl;
	char		*s;

	if ((shlvl = get_env_val("SHLVL")) != NULL)
	{
		lvl = ft_atoi(shlvl);
		if ((s = ft_itoa(lvl + 1)) == NULL)
			return (int_error(EALLOC));
		if (lvl != 0)
			if (modif_env("SHLVL", s) == -1)
			{
				if (g_error == NULL)
					g_error = EALLOC;
				return (-1);
			}
		free(s);
	}
	return (0);
}

static int		init_42sh(char *env[])
{
	int			(*f_init[5])();
	uint8_t		i;

	if (get_newenv(env) == -1)
		return (-1);
	f_init[0] = signal_init;
	f_init[1] = init_env;
	f_init[2] = init_termcaps;
	f_init[3] = create_hashtab;
	f_init[4] = NULL;
	i = 0;
	while (f_init[i] != NULL)
	{
		if (f_init[i]() == -1)
			return (-1);
		++i;
	}
	return (0);
}

int				main(int argc, char **argv, char *env[])
{
	UNUSED(argc);
	UNUSED(argv);
	g_env = NULL;
	g_error = NULL;
	if (init_42sh(env) != 0)
	{
		error("42sh: ");
		exit(EXIT_FAILURE);
	}
	init_set(g_env);
	while (42)
	{
		if (main_core() != 0)
		{
			error("42sh:");
		}
	}
	return (EXIT_SUCCESS);
}
