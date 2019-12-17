/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   more.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 14:34:43 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 18:59:00 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		check_type(const char c)
{
	int i;

	i = 0;
	while (i < _nbtypes && g_conversion_types[i] != c)
		i++;
	return (i < _nbtypes ? i : ERROR);
}

void	print_output(t_args *arg)
{
	int	output_len;

	output_len = ft_strlen(arg->output);
	if (arg->type == _char)
	{
		if (arg->flags.byte[_minus] || arg->width < 0)
		{
			arg->width = ft_abs(arg->width);
			ft_putchar(arg->output[0]);
			while (arg->width-- - output_len > 0)
				ft_putchar(' ');
		}
		else
		{
			while (arg->width-- - output_len > 0)
				ft_putchar(' ');
			ft_putchar(arg->output[0]);
		}
	}
	else if (arg->type == _integer || arg->type == _digit)
	{
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
}
