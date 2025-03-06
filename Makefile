# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f

# Directories
LIBFT_DIR = libft
INCLUDES  = -Iincludes -I$(LIBFT_DIR)

# Libft settings
LIBFT    = $(LIBFT_DIR)/libft.a
LIBFT_SRCS = $(wildcard $(LIBFT_DIR)/*.c)
LIBFT_OBJS = $(LIBFT_SRCS:.c=.o)

# Push_swap settings
NAME    = push_swap
SRCS    = srcs/push_swap.c srcs/cmds.c srcs/helpers.c srcs/input_verification.c \
          srcs/init_stack.c srcs/main.c srcs/small_sort.c srcs/stack_helpers.c
OBJS    = $(SRCS:.c=.o)

# Compilation rules
all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_OBJS)
	@make -C $(LIBFT_DIR)
	@echo "Libft compiled successfully!"

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "Push_swap compiled successfully!"

# Cleanup rules
clean:
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)
	@echo "Cleanup done!"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(LIBFT)
	@echo "Full cleanup done!"

re: fclean all
