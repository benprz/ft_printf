/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pointer.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:23:12 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 15:12:56 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>
#include <stdlib.h>

char	*convert_pointer(va_list ap)
{
	char	*hex;
	char	*output;

	output = NULL;
	if ((hex = g_conversion_functions[_hexa_lowercase](ap)))
	{
		output = ft_strjoin("0x", hex);
		free(hex);
	}
	return (ft_tolower_string(output));
}

int		print_pointer(t_args *arg)
{
	int len;
	int output_len;

	output_len = ft_strlen(arg->output);
	len = output_len;
	if (arg->flags.byte[_minus] || arg->width < 0)
	{
		arg->width = ft_abs(arg->width);
		ft_putstr(arg->output);
		while (arg->width-- - output_len > 0)
		{
			ft_putchar(' ');
			len++;
		}
	}
	else
	{
		while (arg->width-- - output_len > 0)
		{
			ft_putchar(' ');
			len++;
		}
		ft_putstr(arg->output);
	}
	return (len);
}
