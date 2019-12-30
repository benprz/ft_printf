/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_arg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 13:20:00 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/30 20:54:47 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

int		print_output(t_args *arg)
{
	int len;

	len = 0;
	if (arg->type == _char)
	{
		ft_putchar(arg->output[0]);
		len = 1;
	}
	else if (arg->type == _string && (!arg->output || arg->flags.byte[_precision]))
	{
		if (arg->flags.byte[_precision])
			len = ft_putnstr(arg->output, ft_max_value(arg->size, arg->output_len));
		else
			len = ft_putstr("(null)");
	}
	else
		len = ft_putstr(arg->output);
	return (len);
}

int		print_precision(t_args *arg)
{
	int len;

	len = 0;
	if (arg->neg)
	{
		arg->neg = 0;
		ft_putchar('-');
	}
	if (arg->size > 0 && arg->type != _percent && arg->type != _string)
	{
			while (arg->size--)
			{
				ft_putchar('0');
				len++;
			}
	}
	else if (arg->flags.byte[_precision] && !arg->size && (arg->type == _int || arg->type == _digit))
	{
		if (arg->output[0] == '0')
			return (len);
	}
	len += print_output(arg);
	return (len);
}

int		print_width(t_args *arg)
{
	int len;

	len = 0;
	if (arg->neg)
	{
		arg->neg = 0;
		ft_putchar('-');
	}
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

int		print_arg(t_args *arg)
{
	int 	len;
	
	len = 0;
	arg->width = ft_min_value(arg->width - (arg->output_len + arg->size), 0);
	if ((arg->type == _digit || arg->type == _int) && arg->output[0] == '-')
	{
		if (arg->flags.byte[_zero] || arg->flags.byte[_precision])
		{
			ft_replace_string(&arg->output, ft_strdup(&arg->output[1]));
			arg->neg = 1;
			arg->output_len--;
			len++;
		}
	}
	if (arg->type != _string || (arg->output[0] != '0')
		arg->size = ft_min_value(arg->size - arg->output_len, 0);
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
