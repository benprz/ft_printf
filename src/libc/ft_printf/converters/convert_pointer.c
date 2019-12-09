/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_pointer.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:23:12 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 19:07:49 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdarg.h>
#include <stdio.h>

int     convert_pointer(va_list ap)
{
    return (ft_strjoin("0x", g_types_conversion_function[_hexa_uppercase]));
}
