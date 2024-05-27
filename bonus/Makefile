NAME = libso_long_bonus.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SRC = main_bonus.c get_map_zero_bonus.c \
		get_map_one_bonus.c get_map_two_bonus.c \
		get_map_three_bonus.c \
		\
		so_long_bonus.c sprite_zero_bonus.c \
		sprite_one_bonus.c

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
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re