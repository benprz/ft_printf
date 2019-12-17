/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_char.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 19:19:43 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 19:48:36 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>
#include <stdlib.h>

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

void	print_char(t_args *arg)
{
	if (arg->flags.byte[_minus] || arg->width < 0)
	{
		arg->width = ft_abs(arg->width);
		ft_putchar(arg->output[0]);
		while (--arg->width > 0)
			ft_putchar(' ');
	}
	else
	{
		while (--arg->width > 0)
			ft_putchar(' ');
		ft_putchar(arg->output[0]);
	}
}
