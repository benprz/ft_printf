/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 19:28:42 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 20:32:43 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static short	count_chars(int n)
{
	short len;

	len = 1;
	while ((n /= 10))
		len++;
	return (len);
}

char			*ft_itoa(const int n)
{
	char			*str;
	unsigned int	n2;
	short			len;
	short			neg;

	len = count_chars(n);
	n2 = n < 0 ? (unsigned int)-n : (unsigned int)n;
	neg = n < 0;
	if ((str = (char *)ft_calloc(len + neg + 1, sizeof(char))))
	{
		while (len--)
		{
			str[len + neg] = n2 % 10 + '0';
			n2 /= 10;
		}
		if (neg)
			*str = '-';
	}
	return (str);
}
