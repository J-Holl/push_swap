NAME = push_swap 

# Compile
CC = clang
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
INC = -I$(INC_DIR)

# Location
SRC_DIR = src
INC_DIR = inc

# Source files
MAIN = push_swap.c 
PARSING = parsing.c
DLIST = dlist.c dlist_no_malloc.c
MISC = init.c ft_putstr.c
ERROR = error.c
SORT = sort.c fastest_move.c re_organize_b.c organize_b.c sort_five.c \
	   pivot.c prev_pivot_last_pos.c organize_b_misc.c
STACK_OPERATE = swap.c push.c rotate.c reverse.c
SRC = $(addprefix src/, $(MAIN)) \
	$(addprefix src/misc/, $(MISC)) \
	$(addprefix src/sort/, $(SORT)) \
	$(addprefix src/parsing/, $(PARSING)) \
	$(addprefix src/stack_operate/, $(STACK_OPERATE)) \
	$(addprefix src/error/, $(ERROR)) \
	$(addprefix src/double_list/, $(DLIST))

# Object files
OBJ = $(SRC:.c=.o)

# Patern rule 
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re

