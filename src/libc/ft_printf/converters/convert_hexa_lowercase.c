/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_hexa_lowercase.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:12:04 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 18:03:20 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

char	*convert_hexa_lowercase(va_list ap)
{
	return (ft_tolower_string(g_conversion_functions[_hexa_uppercase](ap)));
}
