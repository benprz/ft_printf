/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 20:12:48 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 18:55:59 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

const char			g_conversion_types[_nbtypes] = {
	'c',
	'd',
	'i',
	'u',
	'x',
	'X',
	's',
	'p',
	'%'
};

char				*(*g_conversion_functions[_nbtypes])(va_list) = {
	convert_char,
	convert_int,
	convert_int,
	convert_unsigned,
	convert_hexa_lowercase,
	convert_hexa_uppercase,
	convert_string,
	convert_pointer,
	convert_percent
};

const char			g_flags[_nbflags] = {
	'-',
	'0',
	'*',
	'.',
	'*'
};

int		parse_arg(const char **format, va_list ap, int len)
{
	t_args	arg;

	(*format)++;
	if (init_flags(&(*format), &arg, ap) != ERROR)
	{
		if ((arg.type = check_type(**format)) != ERROR)
		{
			if ((arg.output = g_conversion_functions[arg.type](ap)))
			{
				print_output(&arg);
				free(arg.output);
				return (len);
			}
		}
	}
	return (ERROR);
}

int		parse_format(const char *format, va_list ap)
{
	int len;
	int len2;

	len = 0;
	while (*format && len != ERROR)
	{
		len2 = 1;
		if (*format == '%')
			len = parse_arg(&format, ap, len);
		else
		{
			len2 = ft_strclen(format, '%');
			write(1, format, len2);
			len += len2;
		}
		format += len2;
	}
	return (len);
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

#include <stdio.h>
void	print_flags(t_args *arg)
{
	int i;

	i = 0;
	printf("\n");
	while (i < _nbflags)
	{
		printf("<flags[%c] = %d>\n", g_flags[i], arg->flags.byte[i]);
		i++;
	}
	printf("<width = %d>\n<size = %d>\n", arg->width, arg->size);
}
