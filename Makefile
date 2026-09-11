NAME = codexion

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -I.

SRC = main.c\
	utils/ft_atol.c\
	utils/ft_isspace.c\
	parsing/parse_args.c\
	parsing/parse_args_utils.c

OBJ = $(SRC:.c=.o)
HEADERS = codexion.h

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
