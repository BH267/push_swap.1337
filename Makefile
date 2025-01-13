
SRC = push_swap.c ft_sort.c ps_operations.c ps_operations2.c utils_push_swap.c flists.c ft_split.c

NAME = push_swap
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all :$(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	@$(RM) $(OBJ)

fclean : clean 
	@$(RM) $(NAME)
re : fclean all

