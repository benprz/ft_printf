/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/16 17:47:03 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 18:25:16 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*s2;
	size_t	len;

	s2 = NULL;
	if (s && (len = ft_strlen(s)))
	{
		if ((s2 = (char *)ft_calloc(len + 1, sizeof(char))))
		{
			s += len - 1;
			while (len--)
				s2[len] = f(len, *s--);
		}
	}
	return (s2);
}
