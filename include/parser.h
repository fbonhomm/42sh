/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 10:48:57 by ksoulard          #+#    #+#             */
/*   Updated: 2016/06/01 11:09:19 by ksoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# ifdef _POSIX_MAX_INPUT
#  define OPEN_MAX_INPUT _POSIX_MAX_INPUT
# else
#  define OPEN_MAX_INPUT 255
# endif

# define BUILTIN 1
# define BIN 2

typedef enum		e_subtok
{
	GREAT,
	DGREAT,
	LESS,
	DLESS,
	GREATAND,
	LESSAND,
	LESSGREAT,
	PIPE,
	OR_IF,
	AND_IF,
	SEMI,
	AMPERSAND,
}					t_subtok;

typedef enum		e_token
{
	WORD,
	IO_NUMBER,
	IO_FILE,
	OPERATOR,
}					t_token;

typedef struct		s_lextab
{
	char			*word;
	t_token			token;
	t_subtok		subtok;
	char			separator;
	int				no_parse;
	struct s_lextab	*next;
	struct s_lextab *prev;
}					t_lextab;

typedef struct		s_redir
{
	int				type;
	int				io_num;
	int				io_file;
	char			*name_io_file;
	struct s_redir	*next;
	struct s_redir	*prev;
}					t_redir;

typedef struct		s_cmd
{
	int				pipe[2];
	int				bin_type;
	char			*bin;
	char			**arg_list;
	t_redir			*redir;
	struct s_cmd	*next;
	struct s_cmd	*prev;
	char			*heredoc;
}					t_cmd;

typedef struct		s_input
{
	int				fd;
	int				wr;
	int				re;
	int				close;
}					t_input;

typedef struct		s_allcmd
{
	t_cmd			*cmd;
	t_input			input_tab[OPEN_MAX_INPUT];
	int				last_ret;
	int				what_if;
	pid_t			*child_tab;
	struct s_allcmd	*next;

}					t_allcmd;

typedef struct		s_parser
{
	struct s_allcmd	*allcmd;
	struct s_cmd	*cmd;
	struct s_redir	*redir;
	struct s_lextab *lex;
}					t_parser;

#endif
