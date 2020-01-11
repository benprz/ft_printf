/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   char.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 16:09:47 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 12:05:28 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>
#include <stdlib.h>

char	*convert_char(va_list ap)
{
	char *output;

	if ((output = malloc(sizeof(char) * 2)))
	{
		output[0] = (char)va_arg(ap, int);
		output[1] = '\0';
	}
	return (output);
}
