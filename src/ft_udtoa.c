/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_udtoa.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 11:04:48 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 11:18:03 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

static short	count_chars(unsigned long long n)
{
	short len;

	len = 1;
	while ((n /= 10))
		len++;
	return (len);
}

char			*ft_udtoa(unsigned long long n)
{
	char				*str;
	short				len;

	len = count_chars(n);
	if ((str = (char *)malloc((len + 1) * sizeof(char))))
	{
		str[len] = '\0';
		while (len--)
		{
			str[len] = n % 10 + '0';
			n /= 10;
		}
	}
	return (str);
}
