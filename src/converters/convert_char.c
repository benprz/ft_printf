/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_char.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 19:19:43 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/28 19:23:37 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

int     convert_char(va_list ap)
{
	printf("%c", (unsigned char)va_arg(ap, int));
    return (1);
}