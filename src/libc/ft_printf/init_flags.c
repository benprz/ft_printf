/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_flags.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 17:26:19 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 14:19:33 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	get_precision_size(const char **format, t_args *arg)
{
	(*format)++;
	if (*(*format) == g_flags[_wildcard_size])
		arg->flags.byte[_wildcard_size] = 1;
	else
	{
		arg->size = ft_atoi(*format);
		ft_skip_digit(format);
		(*format)--;
	}
}

int		is_flag(const char **format, t_args *arg)
{
	int i;

	if (ft_isdigit(**format) && **format != g_flags[_zero])
	{
		arg->width = ft_atoi(*format);
		ft_skip_digit(format);
	}
	i = 0;
	while (i < _nbflags)
	{
		if (**format == g_flags[i])
		{
			if (**format == g_flags[_precision])
				get_precision_size(format, arg);
			return ((arg->flags.byte[i] = 1));
		}
		i++;
	}
	return (0);
}

int		init_flags(const char **format, t_args *arg, va_list ap)
{
	int i;

	i = 0;
	arg->flags.value = 0;
	arg->width = 0;
	arg->size = 0;
	while (is_flag(format, arg))
		(*format)++;
	if (arg->flags.byte[_wildcard_width] && arg->width)
		return (ERROR);
	if (arg->flags.byte[_wildcard_width])
		arg->width = va_arg(ap, int);
	if (arg->flags.byte[_wildcard_size])
		arg->size = va_arg(ap, int);
	return (1);
}
