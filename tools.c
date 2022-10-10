/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarquit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 18:08:05 by rmarquit          #+#    #+#             */
/*   Updated: 2022/04/14 18:08:06 by rmarquit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractal.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

double	ft_abs(double x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	ft_atoi(char *s)
{
	int	i;
	int		x;
	int		m;

	x = 0;
	i = 0;
	m = 1;
	if (s[0] == '-')
	{
		m = -1;
		x++;
	}
	if (s[0] == '+')
		x++;
	while (s[x])
	{
		i = i * 10;
		i += s[x++] - '0';
	}
	if (i * m > INT_MAX || i * m < INT_MIN)
	{
		write (1, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	return (i * m);
}
