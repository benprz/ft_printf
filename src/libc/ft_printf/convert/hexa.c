/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   hexa.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 10:01:32 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 16:59:13 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

char	*convert_hexa_uppercase(va_list ap)
{
	return (ft_int2hex(va_arg(ap, unsigned int)));
}

char	*convert_hexa_lowercase(va_list ap)
{
	return (ft_tolower_string(convert_hexa_uppercase(ap)));
}
