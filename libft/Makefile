#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: basle-qu <basle-qu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/06 15:15:27 by basle-qu          #+#    #+#              #
#    Updated: 2015/04/27 12:42:26 by basle-qu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
ft_isprint.c ft_itoa.c ft_memalloc.c ft_memcpy.c ft_memccpy.c ft_memchr.c \
ft_memcmp.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c \
ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_strsub.c \
ft_strtrim.c ft_tolower.c ft_toupper.c ft_strlcat.c ft_strsplit.c \
ft_base.c ft_putaddr.c \
GNL/get_next_line.c \
#PRINTF/flags.c PRINTF/ft_putstring.c PRINTF/modifier2.c PRINTF/modifier.c \
PRINTF/option2.c PRINTF/ft_printf.c PRINTF/option.c PRINTF/special.c \
PRINTF/ft_putlnbr.c PRINTF/ft_putunbr.c

OBJ = ft_atoi.o ft_bzero.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o\
ft_isprint.o ft_itoa.o ft_memalloc.o ft_memcpy.o ft_memccpy.o ft_memchr.o \
ft_memcmp.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o ft_putchar_fd.o \
ft_putendl.o ft_putendl_fd.o ft_putnbr.o ft_putnbr_fd.o ft_putstr.o \
ft_putstr_fd.o ft_strcat.o ft_strchr.o ft_strclr.o ft_strcmp.o ft_strcpy.o \
ft_strdel.o ft_strdup.o ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o \
ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o ft_strncpy.o \
ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o ft_strstr.o ft_strsub.o \
ft_strtrim.o ft_tolower.o ft_toupper.o ft_strlcat.o ft_strsplit.o \
ft_base.o ft_putaddr.o \
get_next_line.o \
#flags.o ft_putstring.o modifier2.o modifier.o option2.o ft_printf.o option.o \
special.o ft_putlnbr.o ft_putunbr.o

NAME = libft.a
CFLAG = -Wall -Wextra -Werror

.PHONY: all test clean fclean re

all: $(NAME)

$(NAME):
	@gcc -c -I includes $(CFLAG) $(SRCS)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[1;36m##########   LIBFT OK   ##########\033[00m"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
