NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME) clean

$(NAME) :
		make -C ./SOLONG/
		$(CC) -o $@ \
		./SOLONG/libso_long.a \
		./PRINTF/libftprintf.a \
		./LIBFT/libft.a\
		./LIST/list.a \
		./minilibx-linux/libmlx.a \
		./minilibx-linux/libmlx_Linux.a \
		-lXext -lX11 -lm

clean :
		make clean -C ./SOLONG/

fclean : clean
		make fclean -C ./SOLONG/
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re