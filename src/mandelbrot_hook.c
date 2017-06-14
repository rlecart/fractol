/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_hook.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 09:56:49 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/14 12:19:38 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		key_hook_mandelbrot(int key, void *param)
{
	t_menu		*men;

	men = ((t_menu*)param);
	if (key == ESC)
		menu(men, 4);
	else
	{
		if (key == RIGHT)
		{
			men->m.x1 -= 0.1;
			men->m.x2 -= 0.1;
		}
		else if (key == LEFT)
		{
			men->m.x1 += 0.1;
			men->m.x2 += 0.1;
		}
		else if (key == UP)
		{
			men->m.y1 += 0.1;
			men->m.y2 += 0.1;
		}
		else if (key == DOWN)
		{
			men->m.y1 -= 0.1;
			men->m.y2 -= 0.1;
		}
		else if (key == PLUS)
		{
			men->m.pom = 1;
		}
		else if (key == MINUS)
		{
			men->m.pom = -1;
		}
		else if (key == BACKSPACE)
		{
			roll_palette(&men->s.pal);
		}
		else if (key == ENTER)
		{
			destroy_window(men);
			init_mandelbrot(&men->m, men->mlx);
		}
		else if (key == KEY_1)
		{
			men->m.imax += 20;
		}
		else if (key == KEY_2)
		{
			men->m.imax -= 20;
		}
		mandelbrot(men);
	}
	return (1);
}

int		mouse_hook_mandelbrot(int button, int x, int y, void *param)
{
	long double		tmp_x;
	long double		tmp_y;
	long double		tmp_x2;
	long double		tmp_y2;
	t_menu		*men;

	men = ((t_menu*)param);
	if (button == 1)
	{
		tmp_x = men->m.x1 + x * (men->m.x2 - men->m.x1) / men->m.image_x;
		tmp_y = men->m.y1 + y * (men->m.y2 - men->m.y1) / men->m.image_y;
		tmp_x2 = men->m.x1;
		tmp_y2 = men->m.y1;
		if (men->m.pom == 1)
		{
			men->m.zoomx *= 2.0;
			men->m.zoomy *= 2.0;
			men->m.imax *= 1.25;
			men->m.x1 = tmp_x - (men->m.x2 - men->m.x1) / 4;
			men->m.x2 = tmp_x + (men->m.x2 - tmp_x2) / 4;
			men->m.y1 = tmp_y - (men->m.y2 - men->m.y1) / 4;
			men->m.y2 = tmp_y + (men->m.y2 - tmp_y2) / 4;
		}
		else
		{
			men->m.zoomx /= 2.0;
			men->m.zoomy /= 2.0;
			men->m.imax /= 1.25;
			men->m.x1 = tmp_x - (men->m.x2 - men->m.x1);
			men->m.x2 = tmp_x + (men->m.x2 - tmp_x2);
			men->m.y1 = tmp_y - (men->m.y2 - men->m.y1);
			men->m.y2 = tmp_y + (men->m.y2 - tmp_y2);
		}
	}
	printf("x1 = %Lf\n", men->m.x1);
	printf("x2 = %Lf\n", men->m.x2);
	printf("y1 = %Lf\n", men->m.y1);
	printf("y2 = %Lf\n\n", men->m.y2);
	mandelbrot(men);
	return (1);
}
