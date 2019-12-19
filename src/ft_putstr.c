/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 10:22:34 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 10:53:43 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

#include <unistd.h>

int		ft_putstr(const char *str)
{
	int ret;

	ret = -1;
	if (str)
		ret = write(1, str, ft_strlen(str));
	return (ret);
}
