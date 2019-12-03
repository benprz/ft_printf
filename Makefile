# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/07 13:38:41 by bperez       #+#   ##    ##    #+#        #
#    Updated: 2019/12/03 16:40:56 by bperez      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = includes/
SRC_DIR = src/
OBJ_DIR = obj/

FT_PRINTF_DIR = ft_printf/
SRC_FT_PRINTF =	ft_printf.c\
				converters/convert_char.c\
				converters/convert_int.c\
				converters/convert_unsigned.c\
				converters/convert_hexa.c\
				converters/convert_string.c\
				converters/convert_pointer.c

LIBC_DIR = libc/
SRC_LIBC =	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_isspace.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strncmp.c\
			ft_strndup.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_tolower.c\
			ft_toupper.c\
			$(addprefix $(FT_PRINTF_DIR),$(SRC_FT_PRINTF))

SRC =	ft_free_2d.c\
		ft_itoa.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strclen.c\
		ft_strjoin.c\
		ft_strmapi.c\
		ft_strtrim.c\
		ft_substr.c\
		$(addprefix $(LIBC_DIR),$(SRC_LIBC))

OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

.PHONY: all clean fclean re debug

all: $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(NAME): $(OBJ)
	ar rus $@ $?

clean:
	/bin/rm -rf obj/

fclean: clean
	/bin/rm -f $(NAME)

debug: $(INC_DIR)
	gcc -Wall -Wextra DEBUG.c $(NAME)

re: fclean all
