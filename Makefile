NAME = push_swap
NAME_BN = checker
SRC = operations.c operations2.c sortfile.c utils.c sortfile_complicated_utils2.c\
					 sortfile_simple_utils.c sortfile_complicated_utils.c push_swap.c
OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror

SRC_BONUS = bonus/operations_bonus.c bonus/operations2_bonus.c  bonus/checker_bonus.c \
				bonus/utils_bonus.c bonus/checker_utils_bonus.c
OBJ_BONUS = ${SRC_BONUS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

CC = cc
LIBFT_DIR = includes/libft
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF_DIR = includes/printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf -o $(NAME)

bonus:$(NAME_BN)

$(NAME_BN):$(OBJ_BONUS) $(LIBFT) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -L$(LIBFT_DIR) -L$(PRINTF_DIR) -lft -lftprintf -o $(NAME_BN)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)


%.o: %.c push_swap.h operations.h bonus/checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME) $(NAME_BN)

re: fclean all

.PHONY: all clean fclean bonus re