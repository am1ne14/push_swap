NAME = push_swap

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I

SRCS = srcs/main.c \
       srcs/big_sort.c \
       srcs/operations_rotate.c \
       srcs/position.c \
       srcs/stack_init.c \
       srcs/input_validation.c \
       srcs/operations_reverse_rotate.c \
       srcs/operation_swap_push.c \
       srcs/push_swap.c \
       srcs/stack_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT_AR = libft/libft.a

INCLUDES = inc/push_swap.h

# Default rule to make the program
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_AR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_AR) -o $(NAME)

# Compile libft if necessary
$(LIBFT_AR):
	@make -s -C $(LIBFT_DIR)

# Compile object files from the source files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	@make -s clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS)

# Clean up everything
fclean:
	@make -s clean -C $(LIBFT_DIR)
	@$(RM) -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

