/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:50:44 by rmarquit          #+#    #+#             */
/*   Updated: 2022/04/12 16:50:45 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	put_pixel_1(t_fractal *f, int depth)
{
	int			pos;

	pos = (f->stats.current_height + (f->stats.current_width * 1080)) * 4;
	if (f->stats.current_height < 1080 \
			&& f->stats.current_width < 720 \
				&& depth == f->stats.iteration)
	{
		f->mlx.addr[pos] = 0x00;
		f->mlx.addr[pos + 1] = 0x00;
		f->mlx.addr[pos + 2] = 0x00;
	}
	else if (f->stats.current_height < 1080 \
				&& f->stats.current_width < 720)
	{
		f->mlx.addr[pos] = f->color.r + (depth * 1.20);
		f->mlx.addr[pos + 1] = f->color.g + (depth * 3.52);
		f->mlx.addr[pos + 2] = f->color.b + (depth * 6.65);
	}
}

int	put_pixel(t_fractal *f)
{
	int		depth;
	double	tmp_width;

	tmp_width = f->stats.current_width;
	while (f->stats.current_height < 1080)
	{
		f->stats.current_width = tmp_width;
		while (f->stats.current_width < 720)
		{
			if (f->stats.type == 1)
				depth = julia (f);
			else if (f->stats.type == 2)
				depth = mandelbrot(f);
			else if (f->stats.type == 3)
				depth = burning_ship(f);
			put_pixel_1(f, depth);
			f->stats.current_width += 1;
		}
		f->stats.current_height += 1;
	}
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img, 0, 0);
	return (0);
}

void	colour_shift(t_fractal *f)
{
	f->color.r *= 1.322;
	f->color.g += 13;
	f->color.b += 23;
}
