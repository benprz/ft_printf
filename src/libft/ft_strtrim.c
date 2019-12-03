/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 18:48:16 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/23 18:11:23 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		check_set(const char *set, const char c)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	size_t	len;

	while (*s1 && check_set(set, *s1))
		s1++;
	len = ft_strlen(s1);
	while (len && check_set(set, s1[len - 1]))
		len--;
	return (ft_strndup(s1, len));
}
