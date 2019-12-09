/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_uitoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 18:36:36 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 18:53:54 by bperez      ###    #+. /#+    ###.fr     */
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

char			*ft_uitoa(const int n)
{
	char			*str;
    long			n2;
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

#include <stdio.h>

int main(void)
{
	printf("%u\n", ft_uitoa(10));
}
