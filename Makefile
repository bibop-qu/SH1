#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: basle-qu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/30 19:38:44 by basle-qu          #+#    #+#              #
#    Updated: 2016/08/30 19:39:44 by basle-qu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS =	srcs/main.c srcs/env.c srcs/tools_env.c srcs/tools.c srcs/exec.c \
	srcs/build_cd.c srcs/tools_bis.c srcs/echo.c
OBJS =	main.o env.o tools_env.o tools.o exec.o build_cd.o tools_bis.o echo.o
NAME = minishell 
CFLAG = -Wall -Wextra -Werror

.PHONY: all test clean fclean re

all: $(NAME)

$(NAME):
	@make -C libft/ fclean
	@make -C libft/
	@make -C libft/ clean	
	@gcc -I includes -c $(CFLAG) $(SRCS)
	@gcc -I includes -L libft/ -lft $(OBJS) -o $(NAME)
	@echo "\033[1;36m########## MINISHELL OK ##########\033[00m"
	@make clean

test: fclean
	@gcc -I includes -c $(CFLAG) -g $(SRCS)
	@gcc -I includes -L libft/ -lft $(OBJS) -o $(NAME)
	@echo "\033[1;36m########## MINISHELL OK ##########\033[00m"
	@make clean

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

cleanall: fclean
	@make -C libft/ fclean

re: fclean $(NAME)
