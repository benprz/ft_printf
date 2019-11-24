/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 20:12:48 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/24 12:37:45 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		parse_arg(char type, va_list args)
{
	unsigned char	c;
	char			*s;
	void			*p;

	if (type == 'c')
	{
		c = (unsigned char)va_arg(args, int);
		printf("%c", c);
		return (1);
	}
	else if (type == 's')
	{
		s = va_arg(args, char*);
		printf("%s", s);
		return (strlen(s));
	}
	else if (type == 'p')
	{
		p = va_arg(args, void*);
		printf("%lu || %p", p, p);
		return (14);
	}
	else if (type == '%')
	{
		printf("%%");
		return (1);
	}
	return (-1);
}

int		parse_format(const char *format, va_list args)
{
	int len;

	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += parse_arg(*format, args);
		}
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
	char *line;

	line = calloc(1, 1);
	printf("[");
	printf("]\n# len = [%d]\n", ft_printf("Hello %p and %p :)", &c, line));
	printf("line = %p = %lu\nc = %p = %lu\n", line, line, &c, &c);
	return (0);
}
