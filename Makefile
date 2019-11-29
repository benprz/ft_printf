# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/07 13:38:41 by bperez       #+#   ##    ##    #+#        #
#    Updated: 2019/11/29 16:08:08 by bperez      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = inc/
FILES = convert/convert_char.c\
		convert/convert_int.c\
		convert/convert_unsigned.c\
		convert/conert_hexa.c\
		convert/convert_string.c\
		convert/convert_pointer.c
OBJ = $(FILES:c=o)

.PHONY: all libft clean fclean re

all: $(NAME)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME): $(OBJ)
	ar rus $@ $?

libft: libft/
	$(MAKE) -C libft/

$(OBJ_DIR):
	mkdir -p $@

clean:
	/bin/rm -f obj/

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
