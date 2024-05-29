CC = gcc

NAME = libftprintf.a

LIBFT = ../LIBFT/libft.a

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

%.o : %.c
		$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME)

$(LIBFT) :
		make -C ../LIBFT/

$(NAME) : $(OBJS) $(LIBFT)
		ar rsc $@ $^

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
