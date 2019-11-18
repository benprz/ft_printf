/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 20:12:48 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 19:54:49 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct 	s_env
{
	int			len;
} 				t_env;

int		parse(const char *format)
{
	int len;

	while ()
}

int		ft_printf(const char *format, ...)
{
	va_list args;
	t_env	printf;

	va_start(args, format);
	while (*format)
		format += parse(format);
	va_end(args);
	return (printf.len);
}

int		main(void)
{
	printf("\n%d\n", ft_printf("Hello %s :)"));
	return (0);
}
