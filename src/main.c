/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelabro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:08:48 by gdelabro          #+#    #+#             */
/*   Updated: 2016/12/09 19:53:11 by gdelabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	ft_ray_trace(void *mlx, void *win, int *tab, int *tab1)
{
	t_ray_trace c;

	c.dx = ABS(tab[0] - tab1[0]);
	c.sx = tab[0] < tab1[0] ? 1 : -1;
	c.dy = ABS(tab[1] - tab1[1]);
	c.sy = tab[1] < tab1[1] ? 1 : -1;
	c.err = (c.dx > c.dy ? c.dx : -c.dy) / 2;
	while (1)
	{
		mlx_pixel_put(mlx, win, tab[0], tab[1], 0x005d00fe);
		if (tab[0] == tab1[0] && tab[1] == tab1[1])
			break ;
		c.e2 = c.err;
		if (c.e2 > -c.dx)
		{
			c.err -= c.dy;
			tab[0] += c.sx;
		}
		if (c.e2 < c.dy)
		{
			c.err += c.dx;
			tab[1] += c.sy;
		}
	}
}

static int	*ft_xy(char ***str, int i, int i2)
{
	int *tab;

	tab = (int*)malloc(sizeof(tab) * 2);
	tab[0] = 400 + (i2 * 17) - (i * 15);
	tab[1] = 100 + (i2 * 10) + (i * 20) - (ft_atoi(str[i][i2]) * 2);
	return (tab);
}

static void	ft_print_screen(char ***t, void *mlx, void *win)
{
	int i;
	int i2;

	(void)mlx;
	(void)win;
	i = -1;
	while (t[++i])
	{
		i2 = -1;
		while (t[i][++i2])
		{
			if (t[i][i2 + 1])
				ft_ray_trace(mlx, win, ft_xy(t, i, i2), ft_xy(t, i, i2 + 1));
			if (t[i + 1])
				ft_ray_trace(mlx, win, ft_xy(t, i, i2), ft_xy(t, i + 1, i2));
		}
	}
}

static int	my_key_funct(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (1);
}

int			main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	char	***tab;

	if (argc != 2)
		return (0);
	tab = ft_file_to_tab(argv[1]);
	if (!(mlx = mlx_init()))
		return (-1);
	win = mlx_new_window(mlx, 1000, 1000, "fenetre Fdf");
	ft_print_screen(tab, mlx, win);
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
	return (0);
}
