/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_string.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:15:54 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 10:34:45 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

char	*convert_string(va_list ap)
{
	return (ft_strdup((char *)va_arg(ap, void *)));
}

int		print_string(t_args *arg)
{
	ft_putstr(arg->output);
	return (0);
}
