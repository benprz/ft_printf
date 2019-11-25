/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: bperez <bperez@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 19:17:56 by bperez       #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 12:37:56 by bperez      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
typedef struct	s_args
{
	void		*arg;
	char		type;
	short		nb_flags;
}				t_args;

typedef struct	s_env
{
	t_args		arg;
	int			len;
}				t_env;
*/

enum e_flags {
	MINUS = 0,
	PLUS = 0,
	ZERO = 0,
	SPACE = 0,
	SHARP = 0,
	POINT = 0,
	WILDCARD = 0
};

#endif
