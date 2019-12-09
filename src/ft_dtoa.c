/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_dtoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 18:36:36 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 11:18:56 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

static short	count_chars(long long n)
{
	short len;

	len = 1;
	while ((n /= 10))
		len++;
	return (len);
}

char			*ft_dtoa(const long long n)
{
	char				*str;
	unsigned long long	n2;
	short				len;
	short				neg;

	len = count_chars(n);
	neg = n < 0;
	n2 = neg ? (unsigned long long)-n : (unsigned long long)n;
	if ((str = (char *)malloc((len + neg + 1) * sizeof(char))))
	{
		str[len + neg] = '\0';
		while (len--)
		{
			str[len + neg] = n2 % 10 + '0';
			n2 /= 10;
		}
		if (neg)
			str[0] = '-';
	}
	return (str);
}
