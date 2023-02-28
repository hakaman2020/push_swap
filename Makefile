# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hman <hman@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2021/04/18 18:10:09 by hman          #+#    #+#                  #
#    Updated: 2021/06/17 15:58:00 by hman          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
NAME = push_swap 
BONUS = checker

# source files
SRC_DIR = src
# checker program
SRC_CHECKER = $(addprefix $(SRC_DIR)/,\
	checker.c \
	parser.c \
	stack.c \
	stack_actions.c \
	stack_operations.c \
	get_next_line.c \
	get_next_line_utils.c)
# push_swap program
SRC_PUSH_SWAP = $(addprefix $(SRC_DIR)/,\
	push_swap.c \
	pre_sort_stack.c \
	parser.c \
	stack.c \
	stack_actions.c \
	stack_sorting.c \
	stack_small_sort.c \
	stack_big_sort.c \
	stack_big_sort_utils.c)
# object files
OBJ_DIR = obj
# checker pogram
OBJ_CHECKER = $(SRC_CHECKER:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
# push_swap program
OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_PUSH_SWAP)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ_PUSH_SWAP)

bonus : $(BONUS)

$(BONUS): $(OBJ_CHECKER)
	$(CC) $(CFLAGS) -o $(BONUS) $(OBJ_CHECKER)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(info $(shell mkdir -p obj))
	$(CC) $(CFLAGS) -c $< -o $@ -g

clean:
	rm -f  $(OBJ_PUSH_SWAP) $(OBJ_CHECKER)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
