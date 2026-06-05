NAME = push_swap

CC = cc
FLAGS = -Wall -Werror -Wextra -g -Ilibft -Iinclude -MMD -MP

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC_DIR = src
OBJ_DIR = objects

SRC = disorder_index.c operations.c operations2.c operations3.c \
sort_medium.c sort_medium2.c sort_simple.c stack_node_utils.c stack_node_utils2.c \
flag_parser.c sort_complex.c sort_complex_utils.c stack_parser.c stack_parser_utils.c ft_parse_input.c \
bench_mode.c bench_mode_utils.c stack_init.c push_swap.c

SRCS = $(SRC:%.c=$(SRC_DIR)/%.c)
OBJ = $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEP = $(OBJ:%.o=%.d)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) -L$(LIBFT_PATH) -lft

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

-include $(DEP)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re:	fclean all

.PHONY: all clean fclean re
