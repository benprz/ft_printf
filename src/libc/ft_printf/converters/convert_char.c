/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_char.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 19:19:43 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 15:00:54 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

void	*convert_char(va_list ap)
{
	char *s;

	if ((s = malloc(sizeof(char) * 2)))
	{
		s[0] = (char)va_arg(ap, int);
		s[1] = '\0';
	}
	return (s);
}