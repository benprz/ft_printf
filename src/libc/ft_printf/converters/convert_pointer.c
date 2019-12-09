/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_pointer.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:23:12 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 17:45:05 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>
#include <stdlib.h>

char	*convert_pointer(va_list ap)
{
	char	*hex;
	char	*output;

	output = NULL;
	if ((hex = g_conversion_functions[_hexa_uppercase](ap)))
	{
		output = ft_strjoin("0x10", hex);
		free(hex);
	}
    return (output);
}
