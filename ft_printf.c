/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 20:12:48 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/20 20:43:50 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static int	parse_format(const char *format, t_env *env)
{
	int len;

	len = 1;
	while (*format != '%')
	{
		write(1, format, 1);
		env->len++;
		format++;
	}
	if (*format == '%')
		len += 2;
	printf();
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list args;
	t_env	env;

	va_start(args, format);
	while (*format)
	{
		format += parse_format(format, &env);
		va_arg(args, char*);
		printf("%s\n", args);
		env.len += strlen(args);
	}
	va_end(args);
	return (env.len);
}

int			main(void)
{
	printf("\nlen = %d\n", ft_printf("Hello %s :)", "Ben"));
	return (0);
}
