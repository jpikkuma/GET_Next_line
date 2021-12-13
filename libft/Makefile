# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpikkuma <jpikkuma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 17:23:52 by jpikkuma          #+#    #+#              #
#    Updated: 2021/11/22 16:03:15 by jpikkuma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCS = ./includes

NAME = libft.a

SRC =			\
ft_atoi.c		\
ft_bzero.c		\
ft_isalnum.c	\
ft_isalpha.c	\
ft_isascii.c	\
ft_isdigit.c	\
ft_isprint.c	\
ft_lstmap.c		\
ft_itoa.c		\
ft_memalloc.c	\
ft_memccpy.c	\
ft_memchr.c		\
ft_memcmp.c		\
ft_memcpy.c		\
ft_memdel.c		\
ft_memmove.c	\
ft_memset.c		\
ft_putchar_fd.c	\
ft_putchar.c	\
ft_putendl_fd.c	\
ft_putendl.c	\
ft_putnbr_fd.c	\
ft_putnbr.c		\
ft_putstr_fd.c	\
ft_putstr.c		\
ft_strcat.c		\
ft_strchr.c		\
ft_strclr.c		\
ft_strcmp.c		\
ft_strcpy.c		\
ft_strdel.c		\
ft_strdup.c		\
ft_strequ.c		\
ft_striter.c	\
ft_striteri.c	\
ft_strjoin.c	\
ft_strlcat.c	\
ft_strlen.c		\
ft_strmap.c		\
ft_strmapi.c	\
ft_strncat.c	\
ft_strncmp.c	\
ft_strncpy.c	\
ft_strnequ.c	\
ft_strnew.c		\
ft_strnstr.c	\
ft_strrchr.c	\
ft_strsplit.c	\
ft_strstr.c		\
ft_strsub.c		\
ft_strtrim.c	\
ft_tolower.c	\
ft_toupper.c	\
ft_lstnew.c		\
ft_lstdelone.c	\
ft_lstdel.c		\
ft_lstadd.c		\
ft_lstiter.c	\
ft_calloc.c		\
ft_strlcpy.c	\
ft_strrev.c		\
ft_isxdigit.c	\
ft_isspace.c	\
ft_islower.c	\
ft_isupper.c	\
ft_sqrt.c		\
ft_abs.c

OBJ =	$(SRC:.c=.o)

.PHONY: all clean fclean re so

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I $(INCS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	gcc -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)
