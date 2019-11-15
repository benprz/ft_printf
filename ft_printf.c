/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/15 20:12:48 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/15 21:12:05 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int		ft_printf(const char *str, ...)
{
	va_list args;

	va_start(args, str);
	while ((s = va_arg(args, char *)))
	{
		printf("%s\n", s);
	}
	va_end(args);
	return (0);
}

int		main(void)
{
	ft_printf("hello", "bonjour", "ohayo", "wena");
	return (0);
}
