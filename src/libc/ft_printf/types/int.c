/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_int.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 19:29:41 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 18:53:59 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

char	*convert_int(va_list ap)
{
    return (ft_itoa(va_arg(ap, int)));
}

void	print_int(t_args *arg)
{
	int output_len;

	output_len = ft_strlen(arg->output);
	if (arg->flags.byte[_minus] || arg->width < 0)
	{
		arg->width = ft_abs(arg->width);
		ft_putstr(arg->output, output_len);
		while (arg->width-- - output_len > 0)
			ft_putchar(' ');
	}
	else
	{
		while (arg->width-- - output_len > 0)
			ft_putchar(arg->flags.byte[_zero] ? '0' : ' ');
		ft_putstr(arg->output, output_len);
	}
}
