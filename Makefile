# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksoulard <ksoulard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/11 13:44:49 by ksoulard          #+#    #+#              #
#    Updated: 2016/08/17 13:53:03 by fbonhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		42sh

CC =		gcc

EXT =		.c

FLAGS =		-Wall -Wextra -Werror

FILE =		main\
			tools_env\
			tools_envinfos\
			parser_file\
			parser_path\
			signal\
			read_tcap\
			tools_hashage\
			tools_hashage_2\
			builtin_core\
			builtin_cd\
			builtin_echo\
			builtin_echo_edit\
			builtin_env\
			builtin_exit\
			builtin_setenv\
			builtin_unsetenv\
			error\
			exec\
			tools_exec\
			parser_backquote\
			parser_backquote_dollar\
			parser_doublequote\
			parser_doublequote_2\
			parser_simplequote\
			parser_proc\
			tools_getenv\
			redirection3\
			parser_lexer\
			parser_lexer2\
			tools_parser\
			parser_lst\
			parser_setlst\
			read\
			read_conf\
			read_conf2\
			read_ctrl\
			read_ctrl2\
			read_data\
			read_handler\
			read_motion\
			read_motion2\
			read_motion3\
			read_list\
			read_list2\
			read_list3\
			read_list4\
			read_operation\
			read_print\
			read_print2\
			redirection\
			redirection2\
			parser_cmd\
			tools_free\
			tools_free2\
			tools_read\
			tools_token\
			tools_builtin\
			parser_tokenise\
			parser_tokenise2\
			tools_tilde\
			memory\
			\
			variable_local/builtin_export\
			variable_local/builtin_unset\
			variable_local/builtin_set\
			variable_local/add_env\
			variable_local/add_node\
			variable_local/conform_set\
			variable_local/delete_node\
			variable_local/exe_funct\
			variable_local/exist\
			variable_local/free_node\
			variable_local/init_set\
			variable_local/new_node\
			variable_local/replace_node\
			variable_local/search_egal_export\
			variable_local/search_parenth\
			variable_local/create_funct\
			variable_local/create_var\
			variable_local/split_var\
			variable_local/valid_char\
			variable_local/update_in_env\
			variable_local/free_tree\
			variable_local/search_in_local\
			\
			lib/ft_free_array\
			lib/ft_free\
			lib/ft_parameter\
			lib/ft_print_str\
			lib/ft_print_str_endl\
			lib/ft_sort_str\
			lib/ft_split\
			lib/ft_strdup_array\
			lib/ft_strepur\
			lib/ft_strjoin_mult\
			lib/ft_tab_to_str\
			lib/ft_split_mult_other\
			lib/ft_split_mult\
			lib/ft_sleep\
			lib/ft_put_array\
			lib/ft_str_one_space\

SOURCE = 	sources/

INCLUDE =	include/

HEADER = 	42sh.h	error.h	read.h parser.h tree.h

FILES =		$(addprefix $(SOURCE), $(addsuffix $(EXT), $(FILE)))

OBJ = $(FILES:$(EXT)=.o)

LIB_DIR =	libft

EXEC=		$(LIB_DIR)/$(LIB_DIR).a

all: 	$(EXEC) $(NAME)

$(EXEC):
		@make -C $(LIB_DIR)

$(NAME): $(OBJ)
		 $(CC) $(FLAGS) -o $(NAME) $(OBJ) $(EXEC) -ltermcap

%.o:	%$(EXT) $(INCLUDE)
		 $(CC) $(FLAGS) -c $< -o $@ -I libft -I$(INCLUDE)

clean:
		rm -rf $(OBJ)
		(cd $(LIB_DIR) && $(MAKE) $@)

fclean: clean
		rm -rf $(NAME)
re: fclean all
