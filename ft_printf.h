/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 19:17:56 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 15:45:54 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PRINT(str) ft_putendl(str);

typedef struct	s_args
{
	void		*arg;
	char		type;
	short		nbflags;
}				t_args;

typedef struct	s_env
{
	t_args		arg;
	int			len;
}				t_env;

void			ft_putendl(const char *str);

#endif
