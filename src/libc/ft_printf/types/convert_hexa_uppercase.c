/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_hexa_uppercase.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 19:09:42 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 17:34:08 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

char	*convert_hexa_uppercase(va_list ap)
{
	return (ft_int2hex(va_arg(ap, unsigned int)));
}
