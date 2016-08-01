/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   job.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 22:56:44 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/25 17:32:56 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOB_H
# define JOB_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <termios.h>
# include <signal.h>
# include <dirent.h>
# include <errno.h>
# include <core.h>
# include <time.h>
# include "set.h"
# include "libft.h"

# define STATUS_RUNNING		0
# define STATUS_DONE		1
# define STATUS_SUSPENDED	2
# define STATUS_CONTINUED	3
# define STATUS_TERMINATED	4
# define STATUS_EXIT		5
# define MAX_JOB			20

typedef struct			s_job
{
	pid_t				pgid;
	pid_t				pid;
	int					status;
	int					mode;
    int					id;
	int					ctrlz;
    char				**command;
	struct s_job		*next;
}						t_job;

typedef struct			s_shell
{
    pid_t				pgid;
	struct termios		term;
	t_job				*first_job;
}						t_shell;

t_shell					*g_shell;

/*
** fonction qui initialise les jobs control
*/
void		init_job(void);

/*
** fonction qui affiche les programme suspendu
*/
int			builtin_job(char **cmd);

/*
** fonction qui execute le programme au premier plan
*/
int			builtin_fg(char **cmd);

/*
** fonction qui execute le programme en arriere plan
*/
int			builtin_bg(char **cmd);

/*
** fonction qui numerote les programmes en arriere plan
*/
int			set_id(t_job *j);

/*
** fonction qui supprime un programme en arriere plan
*/
void		remove_job(t_job *j, t_shell *s);

/*
** fonction qui cree un slot pour recevoir un programme et l'ajoute a la chaine
** des programme d'arriere plan
*/
void		new_job(t_job *j);
void		add_job(t_shell *s, t_job *j);

/*
** fonction qui recherche une eperluette (&)
*/
int			search_ampersand(char *cmd);

/*
** fonction qui retourne le nombre de programme en arriere plan
*/
int			nbr_jobs(t_shell *s);

t_job		*end_job(t_job *j);
t_shell		*update_job(t_shell *s);
void		signal_job(t_shell *s, pid_t pid);
char		**get_name_job(pid_t pid);
int			conform_job(t_shell *s);
void		print_job(t_job *j);
void		zombie(t_job *j, t_shell *s);
void		print_done_job(t_job *j);
t_job		*print_and_return(char *str);

/*
** fonction qui set l'id du programme suspendu
*/
t_job		*search_pid(int pid, t_job *j);

/*
** fonction qui suspend les programmes
*/
int			job_suspend(char **cmd);
void		launch_job(t_shell *s, char **cmd);
void		launch_process(t_job *j);

/*
** fonction d'etat des processus
*/
void		status_job(t_job *j);
void		set_status_job(t_job *j);
void		set_status_jobs(t_job *j);

/*
** lib
*/
int			ft_sleep(long miliseconds);
void		ft_put_array(char **tabl, char *c);
void		ft_free_array(char ***str);
void		ft_free(char **str);
void		ft_print_str_endl(int nb, ...);
int			ft_sort_str(char *s1, char *s2);
char		**ft_split(char const *s, char c, char d);
void		ft_print_str(int nb, ...);
char		*ft_strepur(int nb, char *str, ...);
char		**ft_strdup_array(char **tabl);
char		*ft_strjoin_mult(int nb, ...);
void		ft_perror(char *s);
char		*ft_tab_to_str(char **tabl, char separator);
int			ft_parameter(int nb, char const *str, ...);
int			ft_search_true(char const *s, char *c, int i);
int			ft_search_false(char const *s, char *c, int i);
char		**ft_split_mult(int nb, char const *str, ...);

#endif
