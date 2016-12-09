/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:09:19 by gdelabro          #+#    #+#             */
/*   Updated: 2016/12/09 18:28:47 by gdelabro         ###   ########.fr       */
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

typedef struct	s_coord_point
{
	int			x;
	int			y;
	int			z;
}				t_coord_point;

char			***ft_file_to_tab(char *file);

#endif
