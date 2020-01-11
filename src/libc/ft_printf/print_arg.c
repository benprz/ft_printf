/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_arg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/30 13:20:00 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 12:04:22 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

static int	print_precision(t_args *arg)
{
	int len;

	len = 0;
	if ((arg->type == _int || arg->type == _digit) && arg->output[0] == '-')
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
		len += write(1, arg->flags.byte[_zero] ? "0" : " ", 1);
		arg->width--;
	}
	return (len);
}

static int	print_output(t_args *arg)
{
	int len;

	len = 0;
	if ((arg->type == _int || arg->type == _digit) && arg->output[0] == '-')
		len += ft_putstr(&arg->output[1]);
	else if (arg->type == _char)
		len += write(1, arg->output, 1);
	else
		len = ft_putnstr(arg->output, arg->output_len);
	return (len);
}

void		handle_exceptions(t_args *arg)
{
	if (arg->type == _string && arg->flags.byte[_precision])
	{
		if (arg->size < 0)
			arg->size = arg->output_len;
		else if (arg->size < arg->output_len)
			arg->output_len = arg->size;
		else
			arg->size = 0;
	}
	if (arg->flags.byte[_precision] || arg->flags.byte[_minus])
		arg->flags.byte[_zero] = 0;
	if (arg->flags.byte[_precision] && !arg->size && arg->output[0] == '0')
		arg->output_len = arg->output_len == 3 ? 2 : 0;
	if (arg->type == _int || arg->type == _digit)
	{
		if (!arg->size && arg->width && arg->flags.byte[_zero])
			arg->size = arg->width;
		else if (arg->output[0] == '-')
			arg->size = arg->size ? arg->size + 1 : 0;
	}
	if (arg->type == _percent || arg->size < 0)
		arg->size = 0;
	if (arg->type == _char)
		arg->output_len = 1;
}

int			print_arg(t_args *arg)
{
	int		len;

	len = 0;
	handle_exceptions(arg);
	arg->size = ft_min_value(arg->size - arg->output_len, 0);
	arg->width = ft_min_value(arg->width - (arg->output_len + arg->size), 0);
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
