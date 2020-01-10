/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pointer.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:23:12 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 16:32:16 by bperez      ###    #+. /#+    ###.fr     */
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
	if ((hex = g_conversion_functions[_hexa_lowercase](ap)))
	{
		output = ft_strjoin("0x", hex);
		free(hex);
	}
	return (ft_tolower_string(output));
}
