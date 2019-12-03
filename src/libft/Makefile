# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/07 13:38:41 by bperez       #+#   ##    ##    #+#        #
#    Updated: 2019/11/23 19:18:26 by bperez      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = libft.h
FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c\
		ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c\
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c\
		ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c\
		ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c\
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strnstr.c\
		ft_isspace.c ft_free_2d.c ft_strndup.c ft_strclen.c
OBJ = $(FILES:c=o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME): $(OBJ)
	ar rus $@ $?

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
