/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:08:48 by gdelabro          #+#    #+#             */
/*   Updated: 2016/12/12 15:37:13 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void		ft_ray_trace(void *mlx, void *win, t_coord tab)
{
	t_ray_trace c;

	c.dx = ABS(tab.t[0] - tab.t2[0]);
	c.sx = tab.t[0] < tab.t2[0] ? 1 : -1;
	c.dy = ABS(tab.t[1] - tab.t2[1]);
	c.sy = tab.t[1] < tab.t2[1] ? 1 : -1;
	c.err = (c.dx > c.dy ? c.dx : -c.dy) / 2;
	while (1)
	{
		mlx_pixel_put(mlx, win, tab.t[0], tab.t[1], ft_color(tab));
		if (tab.t[0] == tab.t2[0] && tab.t[1] == tab.t2[1])
			break ;
		c.e2 = c.err;
		if (c.e2 > -c.dx && (c.err -= c.dy) != -321321)
			tab.t[0] += c.sx;
		if (c.e2 < c.dy && (c.err += c.dx) != -321321)
			tab.t[1] += c.sy;
	}
}

static t_coord	ft_xy(char ***str, t_debut t, int i3)
{
	t_coord c;

	c.argv = t.argv;
	c.argc = t.argc;
	c.str = str;
	c.i = t.i;
	c.i2 = t.i2;
	c.i3 = i3;
	c.t = (int*)malloc(sizeof(c.t) * 2);
	c.t[0] = 800 + (t.i2 * 22) - (t.i * 25);
	c.t[1] = 350 + (t.i2 * 15) + (t.i * 19)
		- (ft_atoi(c.str[t.i][t.i2]) / 10 * 25);
	c.t3 = (int*)malloc(sizeof(c.t3) * 2);
	c.t3[0] = c.t[0];
	c.t3[1] = c.t[1];
	c.t2 = (int*)malloc(sizeof(c.t2) * 2);
	if (i3 == 1 && (c.t2[0] = 800 + (t.i2 * 22) - (++t.i * 25)))
		c.t2[1] = 350 + (t.i2 * 15) +
			(t.i * 19) - (ft_atoi(c.str[t.i][t.i2]) / 10 * 25);
	if (i3 == 2 && (c.t2[0] = 800 + (++t.i2 * 22) - (t.i * 25)))
		c.t2[1] = 350 + (t.i2 * 15) +
			(t.i * 19) - (ft_atoi(c.str[t.i][t.i2]) / 10 * 25);
	return (c);
}

static void		ft_print_screen(char ***t, void *mlx, void *win, t_debut t2)
{
	static int	mod = 0;

	if (!mod && ++mod)
		t2.mod++;
	else if (!(mod = 0))
		t2.mod = 0;
	t2.i = -1;
	while (t[++t2.i])
	{
		t2.i2 = -1;
		while (t[t2.i][++t2.i2])
		{
			if (t[t2.i][t2.i2 + 1])
				ft_ray_trace(mlx, win, ft_xy(t, t2, 2));
			if (t[t2.i + 1])
				ft_ray_trace(mlx, win, ft_xy(t, t2, 1));
		}
	}
}

static int		my_key_funct(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (1);
}

int				main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	char	***tab;
	t_debut	c;

	c.i = 0;
	c.i2 = 0;
	c.argv = argv;
	c.argc = argc;
	c.mod = 0;
	if (argc != 3 && argc != 6 && argc != 2 && argc != 5)
	{
		ft_putendl("usage: ./Fdf file mod    or   ./Fdf file R G B mod");
		return (0);
	}
	tab = ft_file_to_tab(argv[1]);
	ft_test_file(tab);
	if (!(mlx = mlx_init()))
		return (-1);
	win = mlx_new_window(mlx, 2560, 1315, "fenetre Fdf");
	ft_print_screen(tab, mlx, win, c);
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
	return (0);
}
