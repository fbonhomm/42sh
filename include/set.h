/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 15:06:38 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/07/28 22:05:50 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <termios.h>
# include <signal.h>
# include <dirent.h>
# include <errno.h>
# include <stdarg.h>
# include <core.h>
# include <parser.h>
# include "libft.h"

# define TRUE		1
# define FALSE		0
// # define bool		int

typedef struct		s_funct
{
	char			*key;
	char			**content;
	struct s_funct	*left;
	struct s_funct	*right;
}					t_funct;

typedef struct		s_var
{
	char			*key;
	char			*value;
	struct s_var	*left;
	struct s_var	*right;
}					t_var;

typedef struct		s_tree
{
	t_var			*var;
	t_funct			*funct;
}					t_tree;

/*
** -- GLOBAL --
*/
t_tree				*g_tree;

/*
** fonction initialisation de arbre
*/
void			init_set(char **env);

/*
** fonction qui ajoute les variable d'envirronement a l'arbre
*/
void			add_env(t_var **v, char **env);

/*
** fonction qui separe les clefs et les valeurs
*/
void			split_var(const char *str, char **k, char **v);

/*
** fonction qui cherche les parenthese pour la  conformiter de la fonction qui
** va dans l'arbre funct ( ex: toto() )
*/
int				search_parenth(char *str);

/*
** fonction qui affichar le contenue de l'arbre sur le terminal
*/
int				builtin_set(char **cmd);

/*
** fonction qui creer des variables/fonction locale
*/
int				create_var(char *cmd);
int				create_funct(char *cmd);

/*
** fonction qui cree un noeud de l'arbre
*/
t_var			*new_node_var(char *key, char *value);
t_funct			*new_node_funct(char *key, char **content);

/*
** fonction qui ajoute un noeud
*/
void			add_node_var(t_var **v, char *key, char *value);
void			add_node_funct(t_funct **f, char *key, char **content);

/*
** fonction qui remplace un noeud
*/
int				replace_node_var(t_var *tmp, t_var *node);
int				replace_node_funct(t_funct *tmp, t_funct *node);

/*
** fonction qui libere la memoire d'un noeud
*/
t_var			*free_node_var(t_var *v, t_var *v1, t_var *tmp);
t_funct			*free_node_funct(t_funct *f, t_funct *f1, t_funct *tmp);

/*
** fonction qui supprime un noeud
*/
int				builtin_unset(char **cmd);
t_var			*delete_node_var(t_var *v, char *command);
t_funct			*delete_node_funct(t_funct *f, char *command);

/*
** fonction qui check si la valeur demander existe
*/
int				exist_var(t_var *v, char *cmd);
int				exist_funct(t_funct *f, char *cmd);

/*
** fonction de conformiter pour entre dans les fonction
*/
int				conform_set_var(char *str);
int				conform_set_funct(char *s);

/*
** fonction de validation du character
*/
int				valid_char_var(char c);
int				valid_char_funct(char c);

/*
** fonction qui exporte variable locale dans l'environement
*/
int				builtin_export(char **cmd);
int				search_egal_export(char *str);

/*
** fonction qui execute une fonction/variable locale
*/
int				exe_funct(char *cmd);
int				exe_var(char **cmd);

/*
** fonction update l'env en fonction des variables locale
*/
void			update_in_env(char *key, char *value);

/*
** liberer la memoire des arbres binaires
*/
void			free_tree();
void			free_tree_var(t_var **v);
void			free_tree_funct(t_funct **f);

/*
** fonction qui replace la variable preceder par un dollar, par sa valeur
*/
int				search_in_local(char **tmp, char **rest, char **s);

/*
** fonction qui retourne la valeur de la variable
*/
char			*return_value(char *cmd);

/*
** lib
*/
void			ft_free_array(char ***str);
void			ft_free(char **str);
void			ft_print_str_endl(int nb, ...);
int				ft_sort_str(char *s1, char *s2);
char			**ft_split(char const *s, char c, char d);
void			ft_print_str(int nb, ...);
char			*ft_strepur(int nb, char *str, ...);
char			**ft_strdup_array(char **tabl);
char			*ft_strjoin_mult(int nb, ...);
void			ft_perror(char *s);
char			*ft_tab_to_str(char **tabl, char separator);
int				ft_parameter(int nb, char const *str, ...);
int				ft_search_true(char const *s, char *c, int i);
int				ft_search_false(char const *s, char *c, int i);
char			**ft_split_mult(int nb, char const *str, ...);

int				pars_setenv(char **args);
int				launch_allcmd(t_allcmd *all, pid_t nb_child);

#endif
