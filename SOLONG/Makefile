NAME = libso_long.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC = main.c

OBJ = $(SRC:.c=.o)

%.o : %.c
		$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME)

$(NAME) : $(OBJ)
		make -C ../LIBFT/
		make -C ../LIST/
		make -C ../PRINTF/
		ar rsc $@ $^

clean :
		make clean -C ../LIBFT/
		make clean -C ../LIST/
		make clean -C ../PRINTF/
		rm -f $(OBJ)

fclean : clean
		make fclean -C ../LIBFT/
		make fclean -C ../LIST/
		make fclean -C ../PRINTF/
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re