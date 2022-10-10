/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:50:58 by rmarquit          #+#    #+#             */
/*   Updated: 2022/04/12 16:50:59 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mandelbrot(t_fractal *f)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	f->stats.depth = 0;
	ci = f->stats.current_width / f->stats.scale + f->stats.yi;
	cr = f->stats.current_height / f->stats.scale + f->stats.xr;
	zr = 0;
	zi = 0;
	while ((zr * zr) + (zi * zi) < 4 \
			&& f->stats.depth < f->stats.iteration)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		f->stats.depth += 1;
	}
	return (f->stats.depth);
}

int	julia(t_fractal *f)
{
	double	ci;
	double	cr;
	double	zr;
	double	zi;
	double	tmp_zr;

	f->stats.depth = 0;
	zi = f->stats.current_width / f->stats.scale + f->stats.yi;
	zr = f->stats.current_height / f->stats.scale + f->stats.xr;
	cr = -0.666;
	ci = 0.420;
	if (f->stats.ci != 0)
	{
		cr = (f->stats.cr / 1000);
		ci = (f->stats.ci / 1000);
	}
	while ((zr * zr) + (zi * zi) < 2 && f->stats.depth < f->stats.iteration)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = (2 * zi) * tmp_zr + ci;
		f->stats.depth += 1;
	}
	return (f->stats.depth);
}

int	burning_ship(t_fractal *f)
{
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	tmp_zr;

	f->stats.depth = 0;
	ci = f->stats.current_width / f->stats.scale + f->stats.yi;
	cr = f->stats.current_height / f->stats.scale + f->stats.xr;
	zr = 0.228;
	zi = 0;
	while ((zr * zr) + (zi * zi) < 4 \
			&& f->stats.depth < f->stats.iteration)
	{
		tmp_zr = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = ft_abs((2 * zi) * tmp_zr) + ci;
		f->stats.depth += 1;
	}
	return (f->stats.depth);
}
