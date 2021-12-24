NAME	=	minishell
#NAME_B	=	minishell_bonus

HEADER	=	minishell.h
#HEADER_B	= ./bonus/so_long_b.h


SRC		= 	*.c
#SRC_B	=	./bonus/so_long_b.c	./bonus/error_nulls_b.c	\
#			./bonus/checker_b.c	./bonus/moving_b.c

OBJS	=	$(SRC:.c=.o)
#OBJS_B	=	$(SRC_B:.c=.o)

GCC		=	gcc
RM		=	rm -f
CFLAGS	=	-Werror -Wextra -Wall

all		:	$(NAME)



.c.o:
		$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(HEADER)
		$(MAKE) -C ./libft
		#$(MAKE) -C ./get_next_line
		$(GCC) $(CFLAGS) $(OBJS) ./libft/libft.a ./get_next_line/get_next_line.a -o $(NAME) -lmlx -framework OpenGL -framework AppKit -I

#bonus	:	$(OBJS_B) $(HEADER_B)
#		$(MAKE) -C ./libft
#		$(MAKE) -C ./get_next_line
#		$(GCC) $(CFLAGS) $(OBJS_B) ./libft/libft.a ./get_next_line/get_next_line.a -o $(NAME_B) -lmlx -framework OpenGL -framework AppKit -I

clean:
		$(MAKE) clean -C ./libft
		#$(MAKE) clean -C ./get_next_line
		$(RM) $(OBJS)
		#$(RM) $(OBJS_B)

fclean	:	clean
		$(MAKE) fclean -C ./libft
		#$(MAKE) fclean -C ./get_next_line
		$(RM) $(NAME)
		#$(RM) $(NAME_B)

re		:	fclean all

.PHONE	:	all clean fclean
