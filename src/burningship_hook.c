/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 09:57:32 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/14 10:20:05 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		key_hook_burningship(int key, void *param)
{
	t_menu		*men;

	men = ((t_menu*)param);
	if (key == ESC)
		menu(men, 4);
	else
	{
		if (key == RIGHT)
		{
			men->b.y1++;
		}
		else if (key == LEFT)
		{
			men->b.y1--;
		}
		else if (key == UP)
		{
			men->b.x1--;
		}
		else if (key == DOWN)
		{
			men->b.x1++;
		}
		else if (key == PLUS)
		{
			men->b.pom = 1;
		}
		else if (key == MINUS)
		{
			men->b.pom = -1;
		}
		else if (key == BACKSPACE)
		{
			roll_palette(&men->s.pal);
		}
		else if (key == ENTER)
		{
			destroy_window(men);
			init_burningship(&men->b, men->mlx);
		}
		burningship(men);
	}
	return (1);
}

int		mouse_hook_burningship(int button, int x, int y, void *param)
{
	long double	tmp_x;
	long double	tmp_y;
	long double	tmp_x2;
	long double	tmp_y2;
	t_menu		*men;

	men = ((t_menu*)param);
	if (button == 1)
	{
		tmp_x = men->b.x1 + x * (men->b.x2 - men->b.x1) / men->b.image_x;
		tmp_y = men->b.y1 + y * (men->b.y2 - men->b.y1) / men->b.image_y;
		tmp_x2 = men->b.x1;
		tmp_y2 = men->b.y1;
		if (men->b.pom == 1)
		{
			men->b.zoomx *= 2;
			men->b.zoomy *= 2;
			men->b.imax *= 1.15;
			men->b.x1 = tmp_x - (men->b.x2 - men->b.x1) / 4;
			men->b.x2 = tmp_x + (men->b.x2 - tmp_x2) / 4;
			men->b.y1 = tmp_y - (men->b.y2 - men->b.y1) / 4;
			men->b.y2 = tmp_y + (men->b.y2 - tmp_y2) / 4;
		}
		else
		{
			men->b.zoomx /= 2;
			men->b.zoomy /= 2;
			men->b.imax /= 1.15;
			men->b.x1 = tmp_x - (men->b.x2 - men->b.x1);
			men->b.x2 = tmp_x + (men->b.x2 - tmp_x2);
			men->b.y1 = tmp_y - (men->b.y2 - men->b.y1);
			men->b.y2 = tmp_y + (men->b.y2 - tmp_y2);
		}
	}
	burningship(men);
	return (1);
}
