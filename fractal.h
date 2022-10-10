/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:11:38 by rmarquit          #+#    #+#             */
/*   Updated: 2022/04/12 17:11:43 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_mlx
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_mlx;

typedef struct s_type
{
	int		iteration;
	int		type;
	int		depth;
	double	current_width;
	double	current_height;
	double	scale;
	double	xr;
	double	yi;
	float	cr;
	float	ci;
}				t_type;

typedef struct s_fractal
{
	t_color		color;
	t_mlx		mlx;
	t_type		stats;
}				t_fractal;

int		main(int argc, char **argv);
// tools
int		check_args(char *argv);
int		ft_strcmp(char *s1, char *s2);
double	ft_abs(double x);
int		ft_atoi(char *s);
//	draw
void	put_pixel_1(t_fractal *f, int depth);
int		put_pixel(t_fractal *f);
void	colour_shift(t_fractal *f);
//	fractals
int		julia(t_fractal *f);
int		mandelbrot(t_fractal *fractol);
int		burning_ship(t_fractal *f);
//	controls
int		key(int key, t_fractal *f);
int		mouse(int key, int x, int y, t_fractal *f);
void	zoom_in(int x, int y, t_fractal *f);
void	zoom_out(int x, int y, t_fractal *f);
#endif