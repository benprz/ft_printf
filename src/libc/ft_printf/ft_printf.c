/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 20:12:48 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 19:08:44 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

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

void				*(*g_types_conversion_function[_nbtypes])(va_list) = {
	convert_char,
	convert_int,
	convert_int,
	convert_unsigned,
	convert_hexa_lowercase,
	convert_hexa_uppercase,
	convert_string,
	convert_pointer
};

const char			g_flags_directive[_nbflags] = {
	'-',
	'0',
	'*',
	'.',
	'*'
};

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		len;

	va_start(ap, format);
	len = parse_format(format, ap);
	va_end(ap);
	return (len);
}
