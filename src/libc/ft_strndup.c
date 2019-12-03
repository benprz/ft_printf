/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/23 17:13:14 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 18:13:59 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stddef.h>

char	*ft_strndup(const char *s1, size_t len)
{
	char	*s2;
    size_t  slen;

    s2 = NULL;
    if (s1 && len > 0)
    {
        if (len > (slen = ft_strlen(s1)))
            len = slen;
        if ((s2 = (char *)ft_calloc(len + 1, sizeof(char))))
        {
            while (len--)
                s2[len] = s1[len];
        }
    }
	return (s2);
}