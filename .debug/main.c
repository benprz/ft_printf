/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 16:03:38 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/15 17:57:38 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int main()
{
	int ret;
//	char *str = malloc(sizeof(char));

	printf("##############################\n");
	printf("printf:    [");

	ret = printf("%u %x %X %c %d %i %p %s %p %d %u %x %X", 150, 150, 150, '0', 150, 150, NULL, "ah", &ret, 150, 2879, 20182, 96362);

	printf("]\n");
	printf("ret = %d\n", ret);
	ft_printf("#############################\n");
	ft_printf("ft_printf: [");

	ret = ft_printf("%u %x %X %c %d %i %p %s %p %d %u %x %X", 150, 150, 150, '0', 150, 150, NULL, "ah", &ret, 150, 2879, 20182, 96362);

	printf("]\n");
	printf("ret = %d\n", ret);
	return (0);
}
