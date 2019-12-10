/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 16:03:38 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 18:03:52 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
	printf("##############################\n");
	printf("printf: [%d]\n", ft_int2hex);
	printf("printf: [%X]\n", ft_int2hex);
	printf("printf: [%x]\n", ft_int2hex);
	printf("printf: [%p]\n", ft_int2hex);
	printf("##############################\n");
	ft_printf("ft_printf: [%d]\n", ft_int2hex);
	ft_printf("ft_printf: [%X]\n", ft_int2hex);
	ft_printf("ft_printf: [%x]\n", ft_int2hex);
	ft_printf("ft_printf: [%p]\n", ft_int2hex);
	printf("##############################\n");
	return (0);
}
