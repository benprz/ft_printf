/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_unsigned.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:02:13 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 12:29:59 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int     convert_unsigned(va_list ap)
{
    printf("%u", va_arg(ap, unsigned int));
    return (0);
}
