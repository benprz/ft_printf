# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/07 13:38:41 by bperez       #+#   ##    ##    #+#        #
#    Updated: 2020/01/10 16:35:07 by bperez      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

INC_DIR = includes/
SRC_DIR = src/
OBJ_DIR = .obj/
DEBUG_DIR = .debug/
DEBUG_NAME = debug

FT_PRINTF_DIR = ft_printf/
SRC_FT_PRINTF =	ft_printf.c\
				init_flags.c\
				print_arg.c\
				convert/char.c\
				convert/int.c\
				convert/unsigned.c\
				convert/hexa.c\
				convert/string.c\
				convert/pointer.c\
				convert/percent.c

LIBC_DIR = libc/
SRC_LIBC =	ft_abs.c\
			ft_atoi.c\
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
			ft_putchar.c\
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

SRC =	ft_dtoa.c\
		ft_free_2d.c\
		ft_itoa.c\
		ft_int2hex.c\
		ft_max_value.c\
		ft_min_value.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putnstr.c\
		ft_putstr.c\
		ft_putstr_fd.c\
		ft_replace_string.c\
		ft_skip_digit.c\
		ft_split.c\
		ft_strclen.c\
		ft_strjoin.c\
		ft_strmapi.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower_string.c\
		ft_udtoa.c\
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
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(DEBUG_DIR)$(DEBUG_NAME)

debug: $(NAME)
	gcc $(CFLAGS) -I ../$(INC_DIR) $(DEBUG_DIR)main.c -o $(DEBUG_DIR)$(DEBUG_NAME) $(NAME) && ./$(DEBUG_DIR)$(DEBUG_NAME)

re: fclean all
