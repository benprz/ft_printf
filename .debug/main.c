/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 16:03:38 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2020/01/08 15:03:00 by bperez      ###    #+. /#+    ###.fr     */
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

	ret = printf("%5d", -10);

	printf("]\n");
	printf("ret = %d\n", ret);
	ft_printf("#############################\n");
	ft_printf("ft_printf: [");

	ret = ft_printf("%5d", -10);

	ft_printf("]\n");
	printf("ret = %d\n", ret);
	return (0);
}
