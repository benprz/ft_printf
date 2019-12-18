/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   more.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 14:34:43 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 16:31:16 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		check_type(const char c)
{
	int i;

	i = 0;
	while (i < _nbtypes && g_conversion_types[i] != c)
		i++;
	return (i < _nbtypes ? i : ERROR);
}
