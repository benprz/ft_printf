/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_unsigned.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:02:13 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 19:19:25 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

void	*convert_unsigned(va_list ap)
{
	return (ft_uitoa(va_arg(ap, unsigned int)));
}
