
SRCS =	srcs/main.c
OBJS =	main.o
NAME = ft_minishell1 
CFLAG = -Wall -Wextra -Werror

.PHONY: all $(NAME) test clean fclean re

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@make -C libft/ clean	
	@gcc -I includes -c $(CFLAG) $(SRCS)
	@gcc -I includes -L libft/ -lft $(OBJS) -o $(NAME)
	@echo "\033[1;36m########## MINISHELL OK ##########\033[00m"

test: fclean
	@gcc -I includes -c $(CFLAG) -g $(SRCS)
	@gcc -I includes -L libft/ -lft $(OBJS) -o $(NAME)
	@make clean

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
