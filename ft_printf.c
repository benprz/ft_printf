/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 20:12:48 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 19:31:34 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	ft_putstr(const char *s)
{
	while (*s)
		write(1, s++, 1);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_env	env;

	va_start(ap, format);
	env.arg.type = 'c';
	va_end(ap);
	return (env.len);
}

int		main(void)
{
	ft_printf("Hello %s :)", "Ben");
	return (0);
}
