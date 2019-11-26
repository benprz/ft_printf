/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 20:12:48 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/26 19:28:03 by bperez      ###    #+. /#+    ###.fr     */
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

int		is_type(const char c)
{
	int i;

	i = 0;
	while (i < _nbtypes && g_type_conversions[i] != c)
		i++;
	return (i < _nbtypes);
}

int		has_flag(const char c, int flags[])
{
	int i;

	i = 0;
	while (i < _nbflags)
	{
		if (g_flag_directives[i] == c)
			return ((flags[i] = 1));
		i++;
	}
	return (0);
}

void	init_flags(const char **format, t_args *arg)
{
	int i;

	i = 0;
	while (i < _nbflags)
		arg->flags[i++] = 0;
	while (has_flag(**format, arg->flags))
		(*format)++;
}

int		parse_arg(const char **format, va_list args, int len)
{
	t_args	arg;

	(*format)++;
	init_flags(format, &arg);
	if (!is_type(**format))
		return (ERROR);
	arg.type = *(*format)++;
	if (arg.type == 'c')
	{
		printf("%c", (unsigned char)va_arg(args, int));
		return len++;
	}
	return (len);
}

int		parse_format(const char *format, va_list args)
{
	int len;

	len = 0;
	while (*format && len != -1)
	{
		if (*format == '%')
			len = parse_arg(&format, args, len);
		else
		{
			printf("%c", *format);
			len++;
			format++;
		}
	}
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	int		len;

	va_start(args, format);
	len = parse_format(format, args);
	va_end(args);
	return (len);
}

int		main(void)
{
	int c;

	printf("[");
	printf("]\n# len = [%d]\n", ft_printf("Hello %-c", 'b'));

	printf("\n\n########################\nprintf()");
	//printf("[%.*f]", -15, 5.156483451534);
	printf("[%0*+-.2f]", 15, 1.0);
	printf("\n########################\n");
	return (0);
}
