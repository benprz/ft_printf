/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 16:18:13 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 19:08:07 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *ptr, const int c, const size_t len)
{
	size_t i;

	i = 0;
	while (i != len)
	{
		if (((unsigned char *)ptr)[i] == (unsigned char)c)
			return ((void *)ptr + i);
		i++;
	}
	return (NULL);
}
