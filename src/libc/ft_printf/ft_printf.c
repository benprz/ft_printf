/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 20:12:48 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 20:30:09 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>
#include <stdio.h>

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
	convert_hexa,
	convert_hexa,
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

void	print_flags(t_args *arg)
{
	int i;

	i = 0;
	printf("\n");
	while (i < _nbflags)
	{
		printf("<flags[%c] = %d>\n", g_flags_directive[i], arg->flags[i]);
		i++;
	}
	printf("<width = %d>\n<size = %d>\n", arg->width, arg->size);
}

void	get_precision_size(const char **format, t_args *arg)
{
	(*format)++;
	if (*(*format) == g_flags_directive[_wildcard_size])
		arg->flags[_wildcard_size] = 1;
	else
	{
		arg->size = ft_atoi(*format);
		ft_skip_digit(format);
		(*format)--;
	}
}

int		has_flag(const char **format, t_args *arg)
{
	int i;

	if (ft_isdigit(**format) && **format != g_flags_directive[_zero])
	{
		arg->width = ft_atoi(*format);
		ft_skip_digit(format);
	}
	i = 0;
	while (i < _nbflags)
	{
		if (**format == g_flags_directive[i])
		{
			if (**format == g_flags_directive[_precision])
				get_precision_size(format, arg);
			return ((arg->flags[i] = 1));
		}
		i++;
	}
	return (0);
}

int		init_flags(const char **format, t_args *arg, va_list ap)
{
	int i;

	i = 0;
	while (i < _nbflags)
		arg->flags[i++] = 0;
	arg->width = 0;
	arg->size = 0;
	while (has_flag(format, arg))
		(*format)++;
	if (arg->flags[_wildcard_width] && arg->width)
		return (ERROR);
	if (arg->flags[_wildcard_width])
		arg->width = va_arg(ap, int);
	if (arg->flags[_wildcard_size])
		arg->size = va_arg(ap, int);
	return (1);
}


int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		len;

	va_start(ap, format);
	len = parse_format(format, ap);
	va_end(ap);
	return (len);
}
