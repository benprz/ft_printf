/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_pointer.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:23:12 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 12:29:43 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int     convert_pointer(va_list ap)
{
    printf("%p", va_arg(ap, void *));
    return (0);
}
