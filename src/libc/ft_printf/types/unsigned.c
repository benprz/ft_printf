/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_unsigned.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:02:13 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 10:07:52 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

char	*convert_unsigned(va_list ap)
{
	return (ft_udtoa(va_arg(ap, unsigned int)));
}

int		print_unsigned(t_args *arg)
{
	(void)arg;
	return (0);
}
