NAME = so_long

BONUS = so_long_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

bonus : $(BONUS)

$(NAME) :
		make -C ./solong/
		$(CC) -o $@ \
		./solong/libso_long.a \
		./printf/libftprintf.a \
		./libft/libft.a \
		./minilibx-linux/libmlx.a \
		./minilibx-linux/libmlx_Linux.a \
		-lXext -lX11 -lm

$(BONUS) :
		make -C ./bonus/
		$(CC) -o $@ \
		./bonus/libso_long_bonus.a \
		./printf/libftprintf.a \
		./libft/libft.a \
		./minilibx-linux/libmlx.a \
		./minilibx-linux/libmlx_Linux.a \
		-lXext -lX11 -lm

clean :
		make clean -C ./bonus/
		make clean -C ./solong/

fclean : clean
		make fclean -C ./bonus/
		make fclean -C ./solong/
		rm -f $(NAME) $(BONUS)

re : fclean all

.PHONY : all clean fclean re