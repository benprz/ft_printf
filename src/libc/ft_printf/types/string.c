/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   string.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:15:54 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 13:37:46 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

char	*convert_string(va_list ap)
{
	void *s;

	if ((s = va_arg(ap, void *)) != NULL)
		return (ft_strdup((char *)s));
	return (ft_strdup("(null)"));
}
