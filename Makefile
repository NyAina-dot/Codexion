NAME = codexion

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -I.

SRC = main.c\
	utils/ft_atol.c\
	utils/ft_isspace.c\
	utils/time.c\
	parsing/parse_args.c\
	parsing/parse_args_utils.c\
	simulation/init_simulation.c\
	simulation/allocate_coders.c\
	simulation/init_coders.c\
	simulation/allocate_dongles.c\
	simulation/init_dongles.c\
	simulation/cleanup_simulation.c\
	simulation/create_threads.c\
	simulation/coder_actions.c\
	simulation/dongles.c\

OBJ = $(SRC:.c=.o)
HEADERS = codexion.h

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
fclean: clean
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
