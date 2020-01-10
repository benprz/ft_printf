/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   unsigned.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:02:13 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 16:32:34 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

char	*convert_unsigned(va_list ap)
{
	return (ft_udtoa(va_arg(ap, unsigned int)));
}
