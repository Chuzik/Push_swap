CC		= gcc
CFLAGS	= -g -Wall -Werror -Wextra
RM		= rm -f

NAME	= push_swap
NAME_BONUS  = checker 

LIBFT_DIR =	./libft
LIBFT =		$(LIBFT_DIR)/libft.a

INCLUDE	= push_swap.h
SRC_FILES	= 	push_swap.c list.c s.c r.c rr.c up_down.c p.c main.c write_stack_and_sum_r_ab.c start_sort.c
BONUS_FILES = push_swap.c list.c s.c r.c rr.c up_down.c p.c main.c write_stack_and_sum_r_ab.c start_sort.c bonus.c
SRC    =    $(addprefix src/, $(SRC_FILES))
BONUS  =	$(addprefix bonus/, $(BONUS_FILES))
OBJ		= $(SRC:.c=.o)
OBJECTS_BONUS  =    $(BONUS:.c=.o)


.PHONY: 	all clean fclean re bonus

all: 	$(NAME)

$(NAME):	$(LIBFT) $(OBJ)  $(INCLUDE)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)

%.o:%.c		
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(MAKE) -C $(LIBFT_DIR) clean
			$(RM) $(OBJ) $(OBJECTS_BONUS)

fclean: 	clean
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(RM) $(NAME) $(NAME_BONUS)

re: 		fclean all

bonus:		$(LIBFT) $(OBJECTS_BONUS) checker.h
			$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) -o $(NAME_BONUS)
