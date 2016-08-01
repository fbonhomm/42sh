/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 08:28:16 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/02 11:58:58 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# define UP			4283163
# define DOWN		4348699
# define LEFT		4479771
# define RIGHT		4414235
# define ENTER		13
# define DELETE 	127
# define DEL		2117294875
# define HOME		4741915
# define END		4610843
# define ALTUP		1096489755
# define ALTDOWN	1113266971
# define CTRLC		3
# define CTRLD		4
# define CTRLF		6
# define CTRLB		2
# define CTRLK		11
# define CTRLU		21
# define CTRLP		16
# define CTRLL		12
# define CTRLI		9
# define ENDOF		4
# define RELAUNCH	2
# define QUOTE		1
# define DQUOTE		1 << 1
# define BQUOTE		1 << 2
# define CURSH		1 << 3
# define SUBSH		1 << 4
# define CROSH		1 << 5

typedef struct		s_line
{
	char			ch;
	struct s_line	*next;
	struct s_line	*prev;
}					t_line;

typedef struct		s_cmline
{
	struct s_line	*line;
	struct s_line	*cur;
	struct s_cmline	*next;
	struct s_cmline	*prev;
	char			*prompt_name;
	int				cur_pos_x;
	int				cur_pos_y;
	int				cur_pos_y_tocm;
	int				cur_pos_term;
	int				cur_pos_line;
	int				cur_pos_cm;
	int				nb_line_toline;
	int				nb_line_tocm;
	int				prompt_len;
	int				line_len;
	int				ch_after_cur;
}					t_cmline;

typedef struct		s_all
{
	struct s_cmline	*cm;
	int				nb_ch;
	struct s_all	*next;
	struct s_all	*prev;
}					t_all;

typedef struct		s_win
{
	char			*term_name;
	int				win_column;
	int				win_line;
	int				quote;
	struct s_line	*copy;
	struct s_all	*all_save;
	struct s_all	*all_act;
}					t_win;

typedef struct		s_readf
{
	unsigned int	value;
	int				(*key_controler)(t_win *, int);
}					t_readf;

/*
**	listes
*/
void				free_key(t_line **line);
void				delete_left_key(t_line **line, int pos);
t_line				*get_current_key(t_line **line, int pos);
t_line				*init_line(char ch);
t_all				*init_allcm(void);
t_cmline			*init_cmline(void);
void				cp_cmline(t_cmline **root_cmline, t_cmline *cm);
t_line				*cp_all_line(t_line *line);
void				cp_allcm(t_all **root_allcm, t_all *allcm);
t_all				*cp_all_allcm(t_all *allcm, t_cmline *cm);
t_cmline			*cp_all_cmline(t_cmline *cm);
void				add_key(int key, t_line **line, int pos);
t_cmline			*add_cmline(t_cmline *cm, t_line *line);
void				add_allcm(t_all **allcm, t_cmline *cm);
void				free_line(t_line **line);
void				free_allcm(t_all	**allcm);
void				free_cmline(t_cmline **cm);
void				free_allcm(t_all **allcm);
void				init_history(t_cmline **history);
void				add_key2(t_line *new, t_line **line, t_line *prev,
					t_line *tmp);

/*
**	termcaps
*/
int					unset_attr(void);
int					set_attr(void);
int					init_termcaps(void);

/*
**	read
*/
int					sh1_read(void);
int					relaunch_read(t_win *term);
int					end_of_read(t_win *term);
int					shput(int c);
int					initialize_read(t_win *term);

/*
**	read_handler
*/
int					read_handler(t_win *term, int key);

/*
**	read_print
*/
int					print_character(t_win *term, int key);
void				print_key(int position, int key);
void				print_keys(t_win *term, t_cmline *cm);
void				print_all_line(t_win *term, t_cmline *cm);
void				print_line(t_win *term, t_line *line, int co);
int					print_add_character(t_win *term, int key);
int					print_history_line(t_win *term, t_line *line);
int					print_deletion(t_win *term);

/*
**	read__data
*/
void				new_data_for_end(t_cmline **cm);
void				new_data_for_relaunch(t_cmline *cm, t_cmline *new);
void				new_prompt_for_relaunch(t_win *term, t_cmline **cm);
void				new_prompt_for_initialize(t_cmline *cm, t_cmline **new);
int					new_cmline_for_read(t_cmline **cm, int dir);

/*
**	read__motion
*/
int					cur_motion_handler(int direction, int nb_occurence);
int					cur_motion_backward(t_win *term, int key);
int					cur_motion_forward(t_win *term, int key);

/*
**	read__motion2
*/
int					cur_motion_up(t_win *term, int key);
int					cur_motion_down(t_win *term, int key);
int					cur_motion_left(t_win *term, int key);
int					cur_motion_right(t_win *term, int key);

/*
**	read__motion3
*/
int					cur_motion_home(t_win *term, int key);
int					cur_motion_end(t_win *term, int key);
int					cur_motion_altdown(t_win *term, int key);
int					cur_motion_altup(t_win *term, int key);
int					del_character(t_win *term, int key);

/*
**	read__conf
*/
void				conf_print(t_win *term, t_cmline **cm);
void				conf_history(t_win *term, t_cmline **cm);
void				conf_motion_left(t_win *term, t_cmline **cm);
void				conf_motion_right(t_win *term, t_cmline **cm);
void				conf_delete(t_win *term, t_cmline **cm);
void				conf_del_print(t_win *term, t_cmline **cm);

/*
**	read__operation
*/
int					text_end_of_read(t_win *term, int key);
int					test_caps(void);
int					nb_ch_after_cur(t_cmline *cm);
int					end_or_relaunch(t_win *term, int key);

/*
**	read__ctrl
*/
int					paste_line(t_win *term, int key);
int					cut_left_line(t_win *term, int key);
int					cut_right_line(t_win *term, int key);
int					copy_left_line(t_win *term, int key);
int					copy_right_line(t_win *term, int key);
int					reset_cmd(t_win *term, int key);
int					kill_read(t_win *term, int key);

#endif
