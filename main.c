/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:50:32 by rmarquit          #+#    #+#             */
/*   Updated: 2022/04/12 16:50:34 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_stats(t_fractal *fractal, char **argv)
{
	fractal->stats.current_height = 0;
	fractal->stats.current_width = 0;
	fractal->stats.scale = 305;
	fractal->stats.iteration = 50;
	fractal->color.r = 0x14;
	fractal->color.g = 0x70;
	fractal->color.b = 0x50;
	fractal->stats.xr = -2.5;
	fractal->stats.yi = -1.21;
	fractal->stats.ci = 0;
	if (fractal->stats.type == 1)
	{
		if (argv[2] && argv[3])
		{
			fractal->stats.cr = ft_atoi(argv[2]);
			fractal->stats.ci = ft_atoi(argv[3]);
		}
		fractal->stats.xr = -1.9;
		fractal->stats.yi = -1.21;
	}
	else if (fractal->stats.type == 3)
	{
		fractal->stats.xr = -2.3;
		fractal->stats.yi = -1.8;
	}
}

int	check_args(char *argv)
{
	if (!ft_strcmp(argv, "julia"))
		return (1);
	else if (!ft_strcmp(argv, "mandelbrot"))
		return (2);
	else if (!ft_strcmp(argv, "ship"))
		return (3);
	else
	{
		write(1, "error: wrong argument! " \
		"use one of these <<ship>> <<mandelbrot>> or <<julia>>\n", 77);
		write(1, "use numbers from -999 to 999 for Julia\n", 39);
		exit (0);
	}
}

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc >= 2)
	{
		fractal.stats.type = check_args(argv[1]);
		fractal.mlx.mlx = mlx_init();
		fractal.mlx.win = mlx_new_window(fractal.mlx.mlx, 1080, 720, "Fractol");
		fractal.mlx.img = mlx_new_image(fractal.mlx.mlx, 1080, 720);
		fractal.mlx.addr = mlx_get_data_addr(fractal.mlx.img,
				&fractal.mlx.bits_per_pixel,
				&fractal.mlx.line_length, &fractal.mlx.endian);
		init_stats(&fractal, argv);
		put_pixel(&fractal);
		mlx_key_hook(fractal.mlx.win, key, &fractal);
		mlx_mouse_hook(fractal.mlx.win, mouse, &fractal);
		mlx_hook(fractal.mlx.win, 2, 1L << 0, close, &fractal);
		mlx_loop(fractal.mlx.mlx);
	}
	else
	{
		write(1, "error: missing argument! " \
		"use one of these <<ship>> <<mandelbrot>> or <<julia>>\n", 79);
	}
	return (0);
}
