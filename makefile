NAME_SERVER = server
NAME_CLIENT = client
CFLAGS = -Wall -Wextra -Werror -I
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJS_SERVER = $(SRC_SERVER:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
LIBFT = lib/Libft
PRINTF = lib/printf

INLIBFT = -L $(LIBFT) -lft
INPRINTF = -L $(PRINTF) -lftprintf

$(NAME_SERVER): $(OBJS_SERVER)
	@cd $(LIBFT) && $(MAKE)
	@cd $(PRINTF) && $(MAKE)
	cc $(OBJS_SERVER) $(INLIBFT) $(INPRINTF)

$(NAME_CLIENT): $(OBJS_CLIENT)
	@cd $(LIBFT) && $(MAKE)
	@cd $(PRINTF) && $(MAKE)
	cc $(OBJS_CLIENT) $(INLIBFT) $(INPRINTF)

all: $(NAME_SERVER) $(NAME_CLIENT)

%.o : %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	@cd $(LIBFT) && $(MAKE) clean
	@cd $(PRINTF) && $(MAKE) clean

fclean: clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@cd $(LIBFT) && $(MAKE) fclean
	@cd $(PRINTF) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
