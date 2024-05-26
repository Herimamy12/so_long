NAME = libso_long.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SRC = main.c get_map.c get_map_next_one.c \
		get_map_next_two.c get_map_next_three.c \
		so_long.c so_long_next_one.c \
		so_long_next_two.c all_last_player.c \
		sprite_zero.c

OBJ = $(SRC:.c=.o)

%.o : %.c
		$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME)

$(NAME) : $(OBJ)
		make -C ../LIBFT/
		make -C ../LIST/
		make -C ../PRINTF/
		make -C ../minilibx-linux/
		ar rsc $@ $^

clean :
		make clean -C ../LIBFT/
		make clean -C ../LIST/
		make clean -C ../PRINTF/
		make clean -C ../minilibx-linux/
		rm -f $(OBJ)

fclean : clean
		make fclean -C ../LIBFT/
		make fclean -C ../LIST/
		make fclean -C ../PRINTF/
		make clean -C ../minilibx-linux/
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re