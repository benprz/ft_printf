/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 20:12:48 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 11:01:47 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		parse_arg(const char *format, va_list args, int len)
{
	enum e_flags	flags;
	int 			witdth;
	int				size;
	char			type;

	return (0);
}

int		parse_format(const char *format, va_list args)
{
	int len;

	len = 0;
	while (*format && len != -1)
	{
		if (*format == '%')
		{
			format++;
			len = parse_arg(format, args, len);
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

	printf("[");
	//printf("]\n# len = [%d]\n", ft_printf("%X", 42949672));

	printf("\n########################\n");
	printf("[%*.*f]", 10, 5, 10.12);
	printf("\n########################\n");
	return (0);
}
