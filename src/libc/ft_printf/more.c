/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   more.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 14:34:43 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 19:56:17 by bperez      ###    #+. /#+    ###.fr     */
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

int		print_string(t_args *arg)
{
	int len;

	if (arg->type == _char)
	{
		ft_putchar(arg->output[0]);
		len = 1;
	}
	else if (arg->type == _string)
	{
		if (arg->output)
			len = ft_putnstr(arg->output, arg->size);
		else
			len = ft_putstr("(null)");
	}
	return (len);
}

int		print_width(t_args *arg)
{
	int len;

	len = 0;
	if (arg->width > 0)
	{
		if (arg->flags.byte[_zero]\
			&& !arg->flags.byte[_minus]\
			&& arg->size <= 0)
		{
			while (arg->width--)
			{
				ft_putchar('0');
				len++;
			}
		}
		else
		{
			while (arg->width--)
			{
				ft_putchar(' ');
				len++;
			}
		}
	}
	return (len);
}

int		print_precision(t_args *arg)
{
	int len;

	len = 0;
	if (arg->size > 0)
	{
		if (arg->type != _string)
		{
			while (arg->size--)
			{
				ft_putchar('0');
				len++;
			}
		}
	}
	len += print_string(&arg);
	return (len);
}

int		print_output(t_args *arg)
{
	int len;
	int output_len;

	len = 0;
	output_len = ft_strlen(arg->output); 
	arg->width -= output_len > arg->size ? output_len : arg->size;
	arg->size -= output_len;
	if (arg->flags.byte[_minus])
	{
		len += print_precision(arg);
		len += print_width(arg);
	}
	else
	{
		len += print_width(arg);
		len += print_precision(arg);
	}
	return (len);
}
