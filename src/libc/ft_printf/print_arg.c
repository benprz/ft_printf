/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_arg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 13:20:00 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 15:09:59 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

static int	print_precision(t_args *arg)
{
	int len;

	len = 0;
	if ((arg->type ==_string || arg->type == _digit) && arg->output[0] == '-')
		len += write(1, "-", 1);
	while (arg->size)
	{
		len += write(1, "0", 1);
		arg->size--;
	}
	return (len);
}

static int	print_width(t_args *arg)
{
	int len;

	len = 0;
	while (arg->width)
	{
		len += write(1, " ", 1);
		arg->width--;
	}
	return (len);
}

static int	print_output(t_args *arg)
{
	int len;

	len = 0;
	if ((arg->type ==_string || arg->type == _digit) && arg->output[0] == '-')
		len += ft_putstr(&arg->output[1]);
	else if (arg->type == _char)
		len += write(1, arg->output, 1);
	else
		len = ft_putstr(arg->output);
	return (len);
}

void		handle_exceptions(t_args *arg)
{
}

int			print_arg(t_args *arg)
{
	int 	len;
	
	len = 0;
	arg->size = ft_min_value(arg->size - ft_strlen(arg->output), 0);
	if ((arg->type ==_string || arg->type == _digit) && arg->output[0] == '-')
		arg->size++;
	arg->width -= ft_strlen(arg->output) + arg->size;
	if (arg->flags.byte[_minus])
	{
		len += print_precision(arg);
		len += print_output(arg);
		len += print_width(arg);
	}
	else
	{
		len += print_width(arg);
		len += print_precision(arg);
		len += print_output(arg);
	}
	return (len);
}
