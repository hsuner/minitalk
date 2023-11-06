NAME = ft_printf/libftprintf.a
NAME_C = client
NAME_S = server
FLAGS = -Wall -Wextra -Werror
FILE1 = client.c
FILE2 = server.c
CC = gcc

BSRCC	= client_bonus.c
BSRCS	= server_bonus.c
NAME_BC = client_bonus
NAME_BS = server_bonus

all: $(NAME)

$(NAME):
	make -C ft_printf
	$(CC) $(FLAGS) $(FILE1) $(NAME) -o $(NAME_C) 
	$(CC) $(FLAGS) $(FILE2) $(NAME) -o $(NAME_S)

bonus: 
	make -C ft_printf
	$(CC) $(FLAGS) $(BSRCC) $(NAME) -o $(NAME_BC) 
	$(CC) $(FLAGS) $(BSRCS) $(NAME) -o $(NAME_BS)
 
clean:
	make clean -C ft_printf
	rm -rf $(NAME_C) $(NAME_S) $(NAME_BC) $(NAME_BS)

fclean: 
	make fclean -C ft_printf
	rm -rf $(NAME_C) $(NAME_S) $(NAME_BC) $(NAME_BS)

re: fclean all

.PHONY: all bonus clean fclean re