MAIN = push_swap.c
FCTS = ft_split.c parsing.c utils_push_swap.c \
       ft_lists.c ft_bubble_sort.c ft_sort.c \
       ps_operations.c handle_tf.c sort_utils.c\
       ps_operations2.c

SRC = $(MAIN) $(FCTS)
BONUS = checker.c gnl/get_next_line.c gnl/get_next_line_utils.c $(FCTS)
NAME = push_swap
BNAME = checker
OBJ = $(SRC:.c=.o)
BOBJ = $(BONUS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all : $(NAME)
	@echo "	\e[32mpush_swap are successfuly maked✅\e[0m"

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(NAME) $(BOBJ)
	@echo "	\e[32mchecker are successfuly maked✅\e[0m"
	@$(CC) $(CFLAGS) $(BOBJ) -o $(BNAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ) $(BOBJ)

fclean : clean
	@$(RM) $(NAME) $(BNAME)

re : fclean all
