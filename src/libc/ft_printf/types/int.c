/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   int.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 16:09:57 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 11:13:24 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

char	*convert_int(va_list ap)
{
    return (ft_itoa(va_arg(ap, int)));
}

int		print_int(t_args *arg)
{
	int output_len;
	int len;

	len = 0;
	output_len = ft_strlen(arg->output);
	if (arg->flags.byte[_minus] || arg->width < 0)
	{
		arg->width = ft_abs(arg->width);
		ft_putstr(arg->output);
		while (arg->width-- - output_len > 0)
			ft_putchar(' ');
	}
	else
	{
		while (arg->width-- - output_len > 0)
			ft_putchar(arg->flags.byte[_zero] ? '0' : ' ');
		ft_putstr(arg->output);
	}
	return (len);
}
