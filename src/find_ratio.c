/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ratio.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 18:22:30 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/14 10:12:58 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	find_ratio_m(t_mandelbrot *m, int x, int y)
{
	long double	original;

	m->image_x = WIN_W;
	m->image_y = WIN_H;
	if (m->image_x > m->image_y)
	{
		original = (long double)y / (long double)x;
		while (m->image_y / m->image_x < original)
			m->image_x--;
	}
	else
	{
		original = (long double)x / (long double)y;
		while (m->image_x / m->image_y < original)
			m->image_y--;
	}
}

void	find_ratio_j(t_julia *j, int x, int y)
{
	long double	original;

	j->image_x = WIN_W;
	j->image_y = WIN_H;
	if (j->image_x > j->image_y)
	{
		original = (long double)y / (long double)x;
		while (j->image_y / j->image_x < original)
			j->image_x--;
	}
	else
	{
		original = (long double)x / (long double)y;
		while (j->image_x / j->image_y < original)
			j->image_y--;
	}
}

void	find_ratio_b(t_burningship *b, int x, int y)
{
	long double	original;

	b->image_x = WIN_W;
	b->image_y = WIN_H;
	if (b->image_x > b->image_y)
	{
		original = (long double)y / (long double)x;
		while (b->image_y / b->image_x < original)
			b->image_x--;
	}
	else
	{
		original = (long double)x / (long double)y;
		while (b->image_x / b->image_y < original)
			b->image_y--;
	}
}
