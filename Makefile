NAME = push_swap
SRC = operations.c operations2.c push_swap.c sortfile.c utils.c utils_sort_file.c complicated_sort.c
OBJ = ${SRC.c=.o}
CFLAGS = -Wall -Wextra 
CC = cc
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) -L$(LIBFT_DIR) -l:libft.a -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re