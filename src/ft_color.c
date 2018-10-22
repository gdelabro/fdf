/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 14:58:20 by gdelabro          #+#    #+#             */
/*   Updated: 2016/12/12 15:27:57 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"
#include <stdio.h>

static t_clr	ft_rgb2(t_coord t, t_clr c)
{
	if ((t.argc == 3 && !ft_atoi(t.argv[2])) || t.argc == 2)
	{
		c.r = 255;
		c.g = 255;
		c.b = 255;
	}
	else if ((t.argc == 6 && !ft_atoi(t.argv[5])) || t.argc == 5)
	{
		c.r = ABS(ft_atoi(t.argv[2])) % 256;
		c.g = ABS(ft_atoi(t.argv[3])) % 256;
		c.b = ABS(ft_atoi(t.argv[4])) % 256;
	}
	return (c);
}

static t_clr	ft_rgb(t_coord t, t_clr c)
{
	if (t.argc == 3 && ft_atoi(t.argv[2]))
	{
		c.r = (255 * c.posz) / 100;
		c.g = (255 * c.posz) / 100;
		c.b = (255 * c.posz) / 100;
	}
	else if (t.argc == 6 && ft_atoi(t.argv[5]))
	{
		c.r = (ABS(ft_atoi(t.argv[2])) % 256 * c.posz) / 100;
		c.g = (ABS(ft_atoi(t.argv[3])) % 256 * c.posz) / 100;
		c.b = (ABS(ft_atoi(t.argv[4])) % 256 * c.posz) / 100;
	}
	else
		c = ft_rgb2(t, c);
	return (c);
}

int				ft_color(t_coord t)
{
	t_clr	c;

	if ((t.i3 == 1 && t.str[t.i][t.i2][0] == '0'
				&& t.str[t.i + 1][t.i2][0] == '0')
			|| (t.i3 == 2 && t.str[t.i][t.i2][0] == '0'
				&& t.str[t.i][t.i2 + 1][0] == '0'))
		c.posz = 0;
	else if ((t.i3 == 1 && t.str[t.i][t.i2][0] == '1'
			&& t.str[t.i + 1][t.i2][0] == '1')
		|| (t.i3 == 2 && t.str[t.i][t.i2][0] == '1'
				&& t.str[t.i][t.i2 + 1][0] == '1'))
		c.posz = 100;
	else if (t.t[0] != t.t3[0] || t.t[1] != t.t3[1])
		c.posz = ((t.t2[0] - t.t[0]) * (100 / (t.t2[0] - t.t3[0])));
	if (((t.i3 == 2 && t.t[1] > t.t2[1]) || (t.i3 == 1 && t.t[1] > t.t2[1])))
		c.posz = 100 - c.posz;
	c = ft_rgb(t, c);
	return (c.r * 256 * 256 + c.g * 256 + c.b);
}
