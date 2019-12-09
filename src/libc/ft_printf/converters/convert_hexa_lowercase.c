/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_hexa_lowercase.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:12:04 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 19:21:33 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

int     convert_hexa_lowercase(va_list ap)
{
	return (ft_tolower_string(g_types_conversion_function[_hexa_lowercase]));
}
