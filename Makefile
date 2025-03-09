NAME = push_swap

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -I inc

SRCS = srcs/main.c \
       srcs/big_sort.c \
       srcs/operations_rotate.c \
       srcs/position.c \
       srcs/stack_init.c \
       srcs/input_validation.c \
       srcs/operations_reverse_rotate.c \
       srcs/operations_swap_push.c \
       srcs/push_swap.c \
       srcs/stack_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT_AR = libft/libft.a

INCLUDES = inc/push_swap.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_AR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_AR) -o $(NAME)

$(LIBFT_AR):
	@make -s -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -s clean -C $(LIBFT_DIR)
	@$(RM) $(OBJS)

fclean: clean
	@make -s clean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
