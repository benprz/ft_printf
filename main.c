/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 16:03:38 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 17:29:20 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/libft.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

int main()
{
	int ret;

	printf("##############################\n");
	printf("printf:    [");

	ret = printf("%%");

	printf("]\n");
	printf("ret = %d\n", ret);
	ft_printf("#############################\n");
	ft_printf("ft_printf: [");

	ret = ft_printf("%%");

	ft_printf("]\n");
	ft_printf("ret = %d\n", ret);
	return (0);
}
