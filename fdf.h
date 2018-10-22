/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:09:19 by gdelabro          #+#    #+#             */
/*   Updated: 2016/12/12 13:22:01 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ABS(x) ((x) < 0 ? - (x) : (x))
# include "libft/libft.h"
# include <mlx.h>
# include <fcntl.h>

typedef struct	s_ray_trace
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			e2;
}				t_ray_trace;

typedef struct	s_coord
{
	int			*t;
	int			*t2;
	char		***str;
	int			*t3;
	int			i;
	int			i2;
	int			i3;
	char		**argv;
	int			argc;
	int			mod;
}				t_coord;

typedef struct	s_clr
{
	int			r;
	int			g;
	int			b;
	int			posz;
}				t_clr;

typedef struct	s_debut
{
	int			i;
	int			i2;
	char		**argv;
	int			argc;
	int			mod;
}				t_debut;

char			***ft_file_to_tab(char *file);
int				ft_color(t_coord tab);
void			ft_test_file(char ***tab);

#endif
