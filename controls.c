/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:39:57 by rmarquit          #+#    #+#             */
/*   Updated: 2022/04/25 17:40:00 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	key(int key, t_fractal *f)
{
	if (key == 53)
		exit(0);
	else if (key == 49)
		colour_shift(f);
	else if (key == 123)
		f->stats.xr -= 10 / f->stats.scale;
	else if (key == 124)
		f->stats.xr += 10 / f->stats.scale;
	else if (key == 126)
		f->stats.yi -= 10 / f->stats.scale;
	else if (key == 125)
		f->stats.yi += 10 / f->stats.scale;
	f->stats.current_height = 0;
	f->stats.current_width = 0;
	put_pixel(f);
	return (0);
}

int	mouse(int key, int x, int y, t_fractal *f)
{
	if (key == 5)
		zoom_in((double)x, (double)y, f);
	if (key == 4)
		zoom_out((double)x, (double)y, f);
	f->stats.current_height = 0;
	f->stats.current_width = 0;
	put_pixel(f);
	return (0);
}

void	zoom_in(int x, int y, t_fractal *f)
{
	double	scale_multi;

		scale_multi = f->stats.scale * 1.3;
		f->stats.xr = ((double)x / f->stats.scale + f->stats.xr) \
			- (scale_multi / 2);
		f->stats.xr += (scale_multi / 2) - ((double)x / scale_multi);
		f->stats.yi = ((double)y / f->stats.scale + f->stats.yi) \
			- (scale_multi / 2);
		f->stats.yi += (scale_multi / 2) - ((double)y / scale_multi);
		f->stats.scale *= 1.3;
		f->stats.iteration += 3;
}

void	zoom_out(int x, int y, t_fractal *f)
{
	double	scale_multi;

	scale_multi = f->stats.scale / 1.3;
	f->stats.xr = ((double)x / f->stats.scale + f->stats.xr) \
			- (scale_multi / 2);
	f->stats.xr += (scale_multi / 2) - ((double)x / scale_multi);
	f->stats.yi = ((double)y / f->stats.scale + f->stats.yi) \
			- (scale_multi / 2);
	f->stats.yi += (scale_multi / 2) - ((double)y / scale_multi);
	f->stats.scale /= 1.3;
	f->stats.iteration -= 3;
}
