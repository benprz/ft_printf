/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 19:17:56 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 17:54:16 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define ERROR -1

# include <stdarg.h>

int					ft_printf(const char *format, ...);

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

extern const char	g_types_conversion_char[_nbtypes];

void				*convert_char(va_list ap);
void				*convert_int(va_list ap);
void				*convert_unsigned(va_list ap);
void				*convert_hexa(va_list ap);
//void				convert_hexa_upper(va_list ap);
void				*convert_string(va_list ap);
void				*convert_pointer(va_list ap);

extern void			*(*g_types_conversion_function[_nbtypes])(va_list);

enum				e_flags
{
	_minus,
	_zero,
	_wildcard_width,
	_precision,
	_wildcard_size,
	_nbflags
};

extern const char	g_flags_directive[_nbflags];

typedef struct		s_args
{
	int				flags[_nbflags];
	int				width;
	int				size;
	int				type;
	void			*output;
}					t_args;

#endif
