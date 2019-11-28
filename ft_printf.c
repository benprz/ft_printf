/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 20:12:48 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 19:21:13 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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

int		is_type(const char c)
{
	int i;

	i = 0;
	while (i < _nbtypes && g_types_conversion_char[i] != c)
		i++;
	return (i < _nbtypes ? i : ERROR);
}

void	skip_digit(const char **format)
{
	while (isdigit(**format))
		(*format)++;
}

void	get_precision_size(const char **format, t_args *arg)
{
	(*format)++;
	if (*(*format) == g_flags_directive[_wildcard_size])
		arg->flags[_wildcard_size] = 1;
	else
	{
		arg->size = atoi(*format);
		skip_digit(format);
		(*format)--;
	}
}

int		has_flag(const char **format, t_args *arg)
{
	int i;

	if (isdigit(**format) && **format != g_flags_directive[_zero])
	{
		arg->width = atoi(*format);
		skip_digit(format);
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

int		parse_arg(const char **format, va_list ap, int len)
{
	t_args	arg;

	(*format)++;
	if (init_flags(&(*format), &arg, ap) != ERROR)
	{
		if ((arg.type = is_type(**format)) != ERROR)
		{
			len += g_types_conversion_function[arg.type](ap);
			return (len);
		}
	}
	return (ERROR);
}

int		parse_format(const char *format, va_list ap)
{
	int len;

	len = 0;
	while (*format && len != ERROR)
	{
		if (*format == '%')
			len = parse_arg(&format, ap, len);
		else
		{
			printf("%c", *format);
			len++;
		}
		format++;
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

int		main(void)
{
	int c;

	printf("[");
	printf("]\n# len = [%d]\n", ft_printf("Hello %-010.*c", 9, 'b'));

	printf("\n\n########################\nprintf()");
	//printf("[%.f]", -15, 5.156483451534);
	printf("[%15.2f]", 1.0);
	printf("\n########################\n");
	return (0);
}
