/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/03 16:03:38 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/10 16:17:35 by bperez      ###    #+. /#+    ###.fr     */
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
#include <limits.h>

int main()
{
	printf("##############################\n");
	printf("printf: [%f]\n", 15.0);
	ft_printf("#############################\n");
	ft_printf("ft_printf: [%.p]\n", "a");
	//ft_printf("##############################\n");
	return (0);
}
