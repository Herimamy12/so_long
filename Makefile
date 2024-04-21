NAME = so_long

CC = gcc

all : $(NAME)

$(NAME) :
		make -C ./SOLONG/
		$(CC) -o $@ \
		./SOLONG/libso_long.a \
		./PRINTF/libftprintf.a \
		./LIBFT/libft.a\
		./LIST/list.a

clean :
		make clean -C ./SOLONG/

fclean : clean
		make fclean -C ./SOLONG/
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re