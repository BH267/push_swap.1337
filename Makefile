SRC = push_swap.c ft_split.c parsing.c utils_push_swap.c ft_lists.c \
      ft_bubble_sort.c ft_sort.c ps_operations.c
NAME = push_swap
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@
clean :
	@$(RM) $(OBJ)

fclean :
	@$(RM) $(NAME)

re : fclean all
