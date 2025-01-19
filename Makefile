
SRC = push_swap.c ft_sort.c ps_operations.c ps_operations2.c utils_push_swap.c ft_lists.c ft_split.c \
      ft_bubble_sort.c ft_is_sorted.c ft_push_swap.c ft_atoi.c handletfs.c
NAME = push_swap
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all :$(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	
%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ)

fclean : clean 
	@$(RM) $(NAME)
re : fclean all

