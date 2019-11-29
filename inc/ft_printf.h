/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 19:17:56 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 14:48:49 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ERROR -1
# include <stdarg.h>

enum				e_types
{
	_char,
	_digit,
	_integer,
	_unsigned,
	_hexa_lowercase,
	_hexa_uppercase,
	_string,
	_pointer,
	_nbtypes
};

const char			g_types_conversion_char[_nbtypes] = {
	'c',
	'd',
	'i',
	'u',
	'x',
	'X',
	's',
	'p'
};

void	*convert_char(va_list ap);
void	*convert_int(va_list ap);
void	*convert_unsigned(va_list ap);
void	*convert_hexa(va_list ap);
//void	convert_hexa_upper(va_list ap);
void	*convert_string(va_list ap);
void	*convert_pointer(va_list ap);

void				*(*g_types_conversion_function[_nbtypes])(va_list) = {
	convert_char,
	convert_int,
	convert_int,
	convert_unsigned,
	convert_hexa,
	convert_hexa,
	convert_string,
	convert_pointer
};

enum				e_flags
{
	_minus,
	_zero,
	_wildcard_width,
	_precision,
	_wildcard_size,
	_nbflags
};

const char			g_flags_directive[_nbflags] = {
	'-',
	'0',
	'*',
	'.',
	'*'
};

typedef struct		s_args
{
	int				flags[_nbflags];
	int				width;
	int				size;
	int				type;
	void			*output;
}					t_args;

#endif
