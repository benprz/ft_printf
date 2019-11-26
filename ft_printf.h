/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 19:17:56 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 19:12:31 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ERROR -1

enum				e_types
{
	_char,
	_digit,
	_integer,
	//_octal,
	_unsigned,
	_hexa_lowercase,
	_hexa_uppercase,
	//_exponent
	//_float
	_string,
	_pointer,
	_nbtypes
};

const char			g_type_conversions[_nbtypes] = {
	'c',
	'd',
	'i',
	//o,
	'u',
	'x',
	'X',
	//e,
	//f,
	's',
	'p'
};

enum				e_flags
{
	_minus,
	//_plus,
	_zero,
	//_blank,
	//_sharp,
	_wildcard,
	_nbflags
};

const char			g_flag_directives[_nbflags] = {
	'-',
	//'+',
	'0',
	//' ',
	//'#',
	'*'
};

typedef struct		s_args
{
	int				flags[_nbflags];
	int				width;
	int				size;
	char			type;
}					t_args;

#endif
