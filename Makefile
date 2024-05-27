NAME = so_long

BONUS = so_long_bonus

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

bonus : $(BONUS)

$(NAME) :
		make -C ./SOLONG/
		$(CC) -o $@ \
		./SOLONG/libso_long.a \
		./PRINTF/libftprintf.a \
		./LIBFT/libft.a \
		./LIST/list.a \
		./minilibx-linux/libmlx.a \
		./minilibx-linux/libmlx_Linux.a \
		-lXext -lX11 -lm

$(BONUS) :
		make -C ./bonus/
		$(CC) -o $@ \
		./bonus/libso_long_bonus.a \
		./PRINTF/libftprintf.a \
		./LIBFT/libft.a \
		./LIST/list.a \
		./minilibx-linux/libmlx.a \
		./minilibx-linux/libmlx_Linux.a \
		-lXext -lX11 -lm

clean :
		make clean -C ./bonus/
		make clean -C ./SOLONG/

fclean : clean
		make clean -C ./bonus/
		make fclean -C ./SOLONG/
		rm -f $(NAME) $(BONUS)

re : fclean all

.PHONY : all clean fclean re