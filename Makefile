NAME = codexion

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -Isrc

SRC = src/main.c\
	src/utils/ft_atol.c\
	src/utils/ft_isspace.c\
	src/utils/time.c\
	src/parsing/parse_args.c\
	src/parsing/parse_args_utils.c\
	src/simulation/init_simulation.c\
	src/simulation/allocate_coders.c\
	src/simulation/init_coders.c\
	src/simulation/allocate_dongles.c\
	src/simulation/init_dongles.c\
	src/simulation/cleanup_simulation.c\
	src/simulation/create_threads.c\
	src/simulation/coder_actions.c\
	src/simulation/dongles.c\
	src/simulation/init_queue.c\
	src/simulation/queue_push.c\
	src/simulation/queue_pop.c\
	src/simulation/queue_compare.c\
	src/simulation/heap.c\
	src/simulation/queue.c\

OBJ = $(SRC:.c=.o)
HEADERS = src/codexion.h

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
