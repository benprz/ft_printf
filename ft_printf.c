/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 20:12:48 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 20:20:27 by bperez      ###    #+. /#+    ###.fr     */
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
	if (*format != '%')
	{
		write(1, format, 1);
		env->len++;
		return (1);
	}
	else
	{
		write(1, format, 1);
		env->len++;
		return (1);
	}
	
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list args;
	t_env	env;

	va_start(args, format);
	printf("env->args = %p\n", env.args);
	va_end(args);
	return (env.len);
}

int			main(void)
{
	printf("\nlen = %d\n", ft_printf("Hello %s :)", "Ben"));
	return (0);
}
