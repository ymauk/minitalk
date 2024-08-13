NAME = libftprintf.a
SRC_MANDATORY = ft_printf.c ft_putnbr.c ft_putstr.c ft_sort_cases.c ft_hexa.c \

mandatory = $(SRC_MANDATORY:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(mandatory)
	ar -rc $(NAME) $(mandatory)
%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
all: $(NAME)
.PHONY: bonus clean fclean re all
