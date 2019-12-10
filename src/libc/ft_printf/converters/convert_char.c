/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_char.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 19:19:43 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 09:54:18 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

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
