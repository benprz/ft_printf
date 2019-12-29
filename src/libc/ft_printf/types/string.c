/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   convert_string.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 12:15:54 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/26 20:21:58 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdarg.h>

char	*convert_string(va_list ap)
{
	return (ft_strdup((char *)va_arg(ap, void *)));
}

int		print_string()
{
	return (0);
}
