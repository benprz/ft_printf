/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   more.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 14:34:43 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 19:14:31 by bperez      ###    #+. /#+    ###.fr     */
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
	int len;

	len = ft_strlen(arg->output);
	if (arg->width > 0)
	{
		if (arg->type == _percent)
		{
			while (--arg->width > 0)
				ft_putchar(arg->flags.byte[_zero] == 1 ? '0' : ' ');
			ft_putchar('%');
		}
	}
	if (arg->flags.byte[_precision])
	{
		if (arg->type == _digit || arg->type == _integer)
		{
			while (arg->size-- - len > 0)
				ft_putchar('0');
			ft_putstr(arg->output, ft_strlen(arg->output));
		}
		if (arg->type == _string)
		{
			len = arg->size < len ? arg->size : len;
			ft_putstr(arg->output, len);
		}
	}
}
