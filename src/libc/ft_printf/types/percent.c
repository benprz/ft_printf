/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   percent.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 16:10:34 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 11:14:14 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char	*convert_percent()
{
	return (ft_strdup("%"));
}

int		print_percent(t_args *arg)
{
	ft_putstr(arg->output);
	return (1);
}
