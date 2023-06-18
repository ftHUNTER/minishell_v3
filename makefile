NAME = minishell
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror  -Ireadline/8.2.1/include 

RM = rm -f
SRC = 	minishell.c \
		parcing/p_str_to_nbr.c \
		parcing/p_split_pro.c \
		parcing/p_fill_lst.c \
		parcing/p_linked_list.c \
		parcing/p_free_all.c \
		parcing/p_fill_lst_count.c \
		parcing/p_remove_cout.c \
		parcing/p_fill_env_list.c\
		parcing/p_expand.c\
		parcing/p_syntax_error.c\
		parcing/p_syntax_error2.c\
		parcing/p_expand_help.c\
		exc/heredoc.c\
		exc/exc.c\
		exc/exit.c\
		exc/export.c\
		exc/getnextline/get_next_line.c\
		exc/getnextline/get_next_line_utils.c\
		exc/echo.c\
		exc/cd.c\
		exc/unset.c\
		exc/pipe_and_cmd.c\
		exc/one_cmd.c\
		exc/open_files.c\
		exc/utils_pipe.c\
		exc/builtins.c\
		exc/utils_export.c\
		exc/utils.c\

OBJ = $(SRC:.c=.o)

all: $(NAME) $(LIBFT)

$(NAME): $(OBJ) $(LIBFT)
	cc $(CFLAGS) $(SRC) $(LIBFT) -lreadline  -L./readline/8.2.1/lib   -o $(NAME) 

$(LIBFT):
	make all -C libft

clean:
	$(RM) $(OBJ)
	make clean -C libft 

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft 

re: fclean all 

# 