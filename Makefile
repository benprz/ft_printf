# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/07 13:38:41 by bperez       #+#   ##    ##    #+#        #
#    Updated: 2019/12/03 12:00:47 by bperez      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = inc/
FILES = ft_printf.c\
		convert/convert_char.c\
		convert/convert_int.c\
		convert/convert_unsigned.c\
		convert/conert_hexa.c\
		convert/convert_string.c\
		convert/convert_pointer.c
OBJ_DIR = obj/
OBJ = $(FILES:%.c=$(OBJ_DIR)%.o)

.PHONY: all libft clean fclean re

all: libft $(NAME)

$(OBJ_DIR)%.o: %.c $(INC)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	ar rus $@ $?

libft: libft/
	$(MAKE) -C libft/

$(OBJ_DIR):
	mkdir -p $@

clean:
	/bin/rm -f obj/
	$(MAKE) -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rn -rf $(OBJ_DIR)
	$(MAKE) -C libft/ fclean

re: fclean all
