/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 19:17:56 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 19:18:45 by bperez      ###    #+. /#+    ###.fr     */
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

enum				e_flags
{
	_minus,
	_zero,
	_wildcard_width,
	_precision,
	_wildcard_size,
	_nbflags
};

typedef struct		s_args
{
	int				flags[_nbflags];
	int				width;
	int				size;
	int				type;
	void			*output;
}					t_args;

extern const char	g_types_conversion_char[_nbtypes];
extern const char	g_flags_directive[_nbflags];
extern void			*(*g_types_conversion_function[_nbtypes])(va_list);

int					ft_printf(const char *format, ...);
int					parse_format(const char *format, va_list ap);
int					init_flags(const char **format, t_args *arg, va_list ap);

void				*convert_char(va_list ap);
void				*convert_int(va_list ap);
void				*convert_unsigned(va_list ap);
void				*convert_hexa_lowercase(va_list ap);
void				*convert_hexa_uppercase(va_list ap);
void				*convert_string(va_list ap);
void				*convert_pointer(va_list ap);

#endif
