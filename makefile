B:= "\033[0;34m"
P:= "\033[0;35m"
R:= "\033[0;31m"
G:= "\033[0;32m"
Y:= "\033[0;33m"
DC:= "\033[0;39m"

NAME_SERVER = server
NAME_CLIENT = client
CFLAGS = -Wall -Wextra -Werror
SRC_SERVER = server.c
SRC_CLIENT = client.c
OBJS_SERVER = $(SRC_SERVER:.c=.o)
OBJS_CLIENT = $(SRC_CLIENT:.c=.o)
LIBFT = lib/Libft
PRINTF = lib/printf

INLIBFT = -L $(LIBFT) -lft
INPRINTF = -L $(PRINTF) -lftprintf

$(NAME_SERVER): $(OBJS_SERVER)
	@echo $(B)"Compiling libft..."$(DC)
	@cd $(LIBFT) && $(MAKE) --silent
	@echo $(P)"Compiling printf...\n"$(DC)
	@cd $(PRINTF) && $(MAKE) --silent
	@echo $(G)"Compiling server..."$(DC)
	@cc $(OBJS_SERVER) $(INLIBFT) $(INPRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	@cd $(LIBFT) && $(MAKE) --silent
	@cd $(PRINTF) && $(MAKE) --silent
	@echo $(G)"Compiling client..."$(DC)
	@cc $(OBJS_CLIENT) $(INLIBFT) $(INPRINTF) -o $(NAME_CLIENT)
	@echo $(Y)"\nminitalk is ready to start"$(DEF_COLOR)

all: $(NAME_SERVER) $(NAME_CLIENT)

%.o : %.c
	@cc $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS_SERVER) $(OBJS_CLIENT)
	@cd $(LIBFT) && $(MAKE) clean --silent
	@cd $(PRINTF) && $(MAKE) clean --silent

fclean: clean
	@rm -f $(NAME_SERVER) $(NAME_CLIENT)
	@cd $(LIBFT) && $(MAKE) fclean --silent
	@cd $(PRINTF) && $(MAKE) fclean --silent
	@echo $(Y)"\nServer and Client are properly cleaned!\n"$(DEF_COLOR)

re: fclean all

.PHONY: all clean fclean re


