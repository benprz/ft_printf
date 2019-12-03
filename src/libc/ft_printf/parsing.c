/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 18:12:40 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 18:27:04 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_type(const char c)
{
	int i;

	i = 0;
	while (i < _nbtypes && g_types_conversion_char[i] != c)
		i++;
	return (i < _nbtypes ? i : ERROR);
}

int		parse_arg(const char **format, va_list ap, int len)
{
	t_args	arg;

	(*format)++;
	if (init_flags(&(*format), &arg, ap) != ERROR)
	{
		if ((arg.type = is_type(**format)) != ERROR)
		{
			if ((arg.output = g_types_conversion_function[arg.type](ap)))
			{
				printf("%s", arg.output);
				return (len);
			}
		}
	}
	return (ERROR);
}

int		parse_format(const char *format, va_list ap)
{
	int len;

	len = 0;
	while (*format && len != ERROR)
	{
		if (*format == '%')
			len = parse_arg(&format, ap, len);
		else
		{
			printf("%c", *format);
			len++;
		}
		format++;
	}
	return (len);
}
