/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 12:26:22 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 18:56:02 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *ptr, const int c, size_t len)
{
	while (len--)
		*((unsigned char *)ptr + len) = (unsigned char)c;
	return (ptr);
}
