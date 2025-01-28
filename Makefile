SRC = push_swap.c ft_split.c parsing.c utils_push_swap.c ft_lists.c \
      ft_bubble_sort.c ft_sort.c ps_operations.c handle_tf.c
NAME = push_swap
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)
	@echo "	\e[32mpush_swap are successfuly maked✅\e[0m"
$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean :
	@$(RM) $(OBJ)

fclean :
	@$(RM) $(NAME)

re : fclean all
