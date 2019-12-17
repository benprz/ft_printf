/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 16:03:38 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 17:39:49 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
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
	printf("##############################\n");
	printf("printf:    [%015.*d]\n", 10, 12);
	ft_printf("#############################\n");
	ft_printf("ft_printf: [%0*i]\n", 15, 12);
	return (0);
}
