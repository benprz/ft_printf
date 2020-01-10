/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_int2hex.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 15:29:45 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 15:09:01 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

short	count_chars(unsigned long n)
{
	int len;

	len = 1;
	while ((n /= 16))
		len++;
	return (len);
}

char	*ft_int2hex(unsigned long n)
{
	char	*str;
	short	len;

	len = count_chars(n);
	if ((str = (char *)malloc(sizeof(char) * (len + 1))))
	{
		str[len] = '\0';
		while (len--)
		{
			if (n % 16 >= 10)
				str[len] = 'A' + (n % 16 - 10);
			else
				str[len] = '0' + n % 16;
			n /= 16;
		}
	}
	return (str);
}
