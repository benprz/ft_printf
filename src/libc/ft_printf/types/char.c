/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   char.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 16:09:47 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 17:20:16 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

char	*convert_char(va_list ap)
{
	char *output;

	if ((output = malloc(sizeof(char) * 2)))
	{
		output[0] = (char)va_arg(ap, int);
		output[1] = '\0';
	}
	return (output);
}

int		print_char(t_args *arg)
{
	int len;

	len = 1;
	if (arg->flags.byte[_minus] || arg->width < 0)
	{
		arg->width = ft_abs(arg->width);
		ft_putchar(arg->output[0]);
		while (--arg->width > 0)
		{
			ft_putchar(' ');
			len++;
		}
	}
	else
	{
		while (--arg->width > 0)
		{
			ft_putchar(' ');
			len++;
		}
		ft_putchar(arg->output[0]);
	}
	return (len);
}
