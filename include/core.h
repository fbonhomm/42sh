/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 15:03:12 by ksoulard          #+#    #+#             */
/*   Updated: 2016/08/14 17:35:16 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include <dirent.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <term.h>
# include <termios.h>
# include <curses.h>
# include <errno.h>
# include "libft.h"
# include "get_next_line.h"
# include <parser.h>
# include <signal.h>
# include <read.h>
# include <error.h>
# include <memory.h>
# include <sys/ioctl.h>
# include <set.h>
# ifndef NSIG
#  ifndef _NSIG
#   error "NSIG not defined"
#  else
#   define NSIG _NSIG
#  endif
# endif
# ifndef POSIX_REALTIME_SIGNALS
#  define NB_SIG_CL SIGRTMIN
# else
#  define NB_SIG_CL NSIG
# endif
# ifdef _POSIX_VERSION
#  include <limits.h>
# endif
# ifndef _POSIX_PATH_MAX
#  define _POSIX_PATH_MAX 256
# endif
# ifndef _POSIX_NAME_MAX
#  define _POSIX_NAME_MAX 14
# endif
# ifndef _POSIX_ARG_MAX
#  define _POSIX_ARG_MAX 4096
# endif
# ifndef _POSIX_CHILD_MAX
#  define _POSIX_CHILD_MAX 25
# endif
# ifndef _POSIX_OPEN_MAX
#  define _POSIX_OPEN_MAX 20
# endif
# ifdef NAME_MAX
#  define NAME_MAX_MIN _XOPEN_NAME_MAX
# else
#  define NAME_MAX_MIN _POSIX_NAME_MAX
# endif
# ifdef PATH_MAX
#  define PATH_MAX_MIN _XOPEN_PATH_MAX
# else
#  define PATH_MAX_MIN _POSIX_PATH_MAX
# endif
# define ARG_MAX_MIN _POSIX_ARG_MAX
# ifdef CHILD_MAX
#  define CHILD_MAX_MIN CHILD_MAX
# else
#  define CHILD_MAX_MIN _POSIX_CHILD_MAX
# endif
# ifdef OPEN_MAX
#  define OPEN_MAX_MIN OPEN_MAX
# else
#  define OPEN_MAX_MIN _POSIX_OPEN_MAX
# endif

# define OSH_APND 1
# define OSH_READ 2
# define OSH_WRITE 4
# define OSH_EXEC 8
# define NBR_BUILTIN 9
# define UNUSED(x) (void)x;

char				*g_error;
char				**g_env;

typedef struct		s_lhash
{
	char			*name;
	char			*path;
	struct s_lhash	*next;
}					t_lhash;

typedef struct		s_hash
{
	t_lhash			*lhash;
}					t_hash;

/*
**					Error
*/
void				error(char *s);
int					parse_error(char *c);
int					int_error(char *value);
int					error_redirection(char *error, int fd);
int					builtin_error(char *builtin, char *file);

/*
**					Builtins
*/
int					builtin_core(t_cmd *cmd);
int					execve_builtin(char **arg_list);
int					builtin_cd(char **arg_list);
int					builtin_echo(char **cmd_list);
char				*replace_str(char *str, int i, char c, int modify);
char				*delete_str(char *str, int i, int modify);
int					backslash_echo_check(char *str);
int					builtin_env(char **arg_list);
int					builtin_exit(char **cmd_list);
int					builtin_setenv(char **arg_list);
int					builtin_unsetenv(char **arg_list);

/*
**					Exec
*/
void				exec_binary(t_cmd *cmd);
void				exec_builtin(t_cmd *cmd);
int					exec_child(t_cmd *cmd, t_input *input_tab);
int					exec_exec(t_cmd *cmd, pid_t *child_tab, t_input *input_tab);
int					exec_cmd(t_cmd *cmd, pid_t *child_tab, t_input *input_tab);

/*
**					Parser
*/
int					main_core(void);
int					parser(char *str);
int					format_lextab(void);
int					format_lextab2(t_lextab **begin);
void				set_input_tab(t_input *input_tab);
int					f_testfile(char *path, char *file, char type, short mode);
int					f_type(char *path, char type);
int					f_type2(struct stat st, char type);
int					f_isexec(char *path, short mode);
int					f_cpy(int fd1, int fd2);
int					wait_child(pid_t *child_tab, int forks);
size_t				count_child(t_cmd *cmd);
char				*replace_dollar(char *s, int *i);
char				*format_simplequote(char *str);
char				*format_doublequote(char *str2, int quote);
char				*handle_backquote(char *str, int *i);
char				*handle_dollar(char *str, int *i);
char				*handle_backslash(char *str, int *i);
char				*format_backquote(char *str);
char				*backquote_good(char *str, int *i, int len);
char				*remove_backquote(char *str);
char				*handle_comp(char *str, int *type, int test);
int					apply_redirection(t_redir *redir, t_input *input_tab);
int					apply_greatand(t_redir redir, t_input *input_tab);
int					apply_lessgreat(t_redir red, t_input *input_tab);
int					open_file_descriptor(t_input *input, int flags, char const
					*file);
int					close_file_descriptor(t_input *input);
int					get_word(char *line, char **new_word, int pos);
int					get_operator_word(char *line, int i, int pos);
int					get_quote_word(char *line, int i, int pos);
int					get_simple_word(char *line, int i, int pos);
int					check_backslash(char *c, int pos);
int					add_file_redir(t_lextab *lex, t_redir **redir);
void				add_lst_allcmd(t_allcmd *allnew);
void				add_lst_cmd(t_cmd **cmd, t_cmd *new_cmd);
void				add_lst_redir(t_redir **redir, t_redir *new);
int					create_cmd_lst(t_lextab *lex);
int					add_allcmd(t_lextab *lex, t_lextab *end);
int					apply_dless(t_redir redir, t_input *input_tab);
int					apply_less(t_redir redir, t_input *input_tab);
int					apply_dgreat(t_redir redir, t_input *input_tab);
int					apply_great(t_redir redir, t_input *input_tab);
int					apply_lessand(t_redir redir, t_input *input_tab);
t_lextab			*new_elem(char **str);
void				add_lex(t_lextab **lex, t_lextab **begin, char **word);
void				add_list_lex(t_lextab **lex, t_lextab **begin, char *word);
int					lexer2(char **word, char *act, t_lextab **begin);
int					lexer(char *str);
int					read_heredoc(int fd, char *end);
int					add_here_document(t_allcmd *all);
int					remove_here_document(t_cmd *cmd);
int					parse_and_tokenise(void);
t_subtok			add_operator(char *operator);
char				*cmp_operand(char *operand);
void				handle_moins_n(char **cmd_list, int *i, int *new_line);

/*
**					Tools
**01010100 01001111 01001111 01001100 01010011
**				54 4F 4F 4C 53
*/
int					read_is_quote(int x);
int					read_close_quote(int x);
int					read_open_quote(int x);
int					get_newenv(char **env);
char				*get_env_val(char *var);
char				*get_env_line(char *var);
char				*strcatstr(char *s1, char *s2, char *op);
int					modif_env(char *var, char *value);
int					expand_env(char *new_line);
void				free_brain(int choice);
void				free_hash(void);
void				free_cmd(t_cmd **cmd);
void				free_redir(t_redir **redir);
int					signal_init(void);
int					create_hashtab(void);
char				*get_path_hash(char *name, t_hash **hash);
t_lhash				*add_lhash(t_lhash **begin_lhash, char *name, char *path);
char				*g_get_env(char *var);
char				*get_shlvl(char *shlvl);
char				*get_pwd(char *pwd);
char				*get_oldpwd(char *oldpwd);
char				*get_paths(char *paths);
int					parser_path(char *path, char type, short mode);
char				*modifpath(char *path);
int					hashage(char *name);
char				*get_name_hash(char *name, t_hash *hash[]);
int					count_bin(char **paths);
int					count_bin2(char *path, int nb_bin);
char				**get_args(char **arg_list);
char				*get_options(char **args);
char				parser_opt(char *opts, char *opt);
int					convert_tilde(char **path);
int					last_ret(int ret, int read);
int					is_separ(int tok);
int					is_redir(int tok);
int					is_great(int tok);
int					is_less(int tok);
int					close_fd(int fd);
int					pipe_fd(int pipefd[2]);
int					dup_fd(int fd1, int fd2);
int					fork_child(pid_t *child);
int					is_operator(char c);
int					is_blank(char c);
int					is_quote(char c);
void				error_exec(char *c);
int					sigint(int mod);
/*
**					Job Control
*/
int					builtin_jobs(char **cmd);
int					builtin_bg(char **cmd);
int					builtin_fg(char **cmd);

#endif
