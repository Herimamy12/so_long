CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = list.a

SRC = list_utils.c list_next.c

OBJ = $(SRC:.c=.o)

%.o : %.c
		$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME)

$(NAME) : $(OBJ)
		ar rsc $@ $^

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
