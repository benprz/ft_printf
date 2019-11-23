/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 20:12:48 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 23:27:01 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int		parse_format(char *format, va_list *args)
{
	while (*format)
	{
		if (*format == '%')
		{
			format += parse_arg(format, )
		}
		else
			printf("%c", *format);
		format++;
	}
	return (0);
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	//t_env	env;

	va_start(args, format);
	parse_format(format, &args);
	va_end(args);
	return (0);
}

int		main(void)
{
	ft_printf("Hello %s :)", "Ben");
	return (0);
}
