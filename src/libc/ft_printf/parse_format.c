/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_format.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 18:12:40 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 10:14:24 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_flags(t_args *arg)
{
	int i;

	i = 0;
	printf("\n");
	while (i < _nbflags)
	{
		printf("<flags[%c] = %d>\n", g_flags[i], arg->flags.byte[i]);
		i++;
	}
	printf("<width = %d>\n<size = %d>\n", arg->width, arg->size);
}

int		check_type(const char c)
{
	int i;

	i = 0;
	while (i < _nbtypes && g_conversion_types[i] != c)
		i++;
	return (i < _nbtypes ? i : ERROR);
}

int		parse_arg(const char **format, va_list ap, int len)
{
	t_args	arg;

	(*format)++;
	if (init_flags(&(*format), &arg, ap) != ERROR)
	{
		if ((arg.type = check_type(**format)) != ERROR)
		{
			if ((arg.output = g_conversion_functions[arg.type](ap)))
			{
				ft_putstr(arg.output);
				free(arg.output);
				return (len);
			}
		}
	}
	return (ERROR);
}

int		parse_format(const char *format, va_list ap)
{
	int len;
	int len2;

	len = 0;
	while (*format && len != ERROR)
	{
		len2 = 1;
		if (*format == '%')
			len = parse_arg(&format, ap, len);
		else
		{
			len2 = ft_strclen(format, '%');
			write(1, format, len2);
			len += len2;
		}
		format += len2;
	}
	return (len);
}
