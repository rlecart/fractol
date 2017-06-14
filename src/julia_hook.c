/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 09:13:09 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/14 10:20:16 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		mouse_motion_hook_julia(int x, int y, void *param)
{
	t_menu		*men;

	men = (t_menu*)param;
	if (men->j.motion == 1)
	{
		men->j.c_r = x / men->j.image_x;
		men->j.c_i = y / men->j.image_y;
	}
	julia(men);
	return (1);
}

int		key_hook_julia(int key, void *param)
{
	t_menu		*men;

	men = ((t_menu*)param);
	if (key == ESC)
	{
		men->j.motion = 0;
		menu(men, 4);
	}
	else
	{
		if (key == RIGHT)
		{
			men->j.y1++;
		}
		else if (key == LEFT)
		{
			men->j.y1--;
		}
		else if (key == UP)
		{
			men->j.x1--;
		}
		else if (key == DOWN)
		{
			men->j.x1++;
		}
		else if (key == PLUS)
		{
			men->j.pom = 1;
		}
		else if (key == MINUS)
		{
			men->j.pom = -1;
		}
		else if (key == BACKSPACE)
		{
			roll_palette(&men->s.pal);
		}
		else if (key == ENTER)
		{
			destroy_window(men);
			init_julia(&men->j, men->mlx);
		}
		else if (key == SPACE)
		{
			if (men->j.motion == 0)
				men->j.motion = 1;
			else
				men->j.motion = 0;
		}
		julia(men);
	}
	printf("key = %d\n", key);
	return (1);
}

int		mouse_hook_julia(int button, int x, int y, void *param)
{
	long double		tmp_x;
	long double		tmp_y;
	long double		tmp_x2;
	long double		tmp_y2;
	t_menu		*men;

	men = ((t_menu*)param);
	if (button == 1)
	{
		tmp_x = men->j.x1 + x * (men->j.x2 - men->j.x1) / men->j.image_x;
		tmp_y = men->j.y1 + y * (men->j.y2 - men->j.y1) / men->j.image_y;
		tmp_x2 = men->j.x1;
		tmp_y2 = men->j.y1;
		if (men->j.pom == 1)
		{
			men->j.zoomx *= 2;
			men->j.zoomy *= 2;
			men->j.imax *= 1.1;
			men->j.x1 = tmp_x - (men->j.x2 - men->j.x1) / 4;
			men->j.x2 = tmp_x + (men->j.x2 - tmp_x2) / 4;
			men->j.y1 = tmp_y - (men->j.y2 - men->j.y1) / 4;
			men->j.y2 = tmp_y + (men->j.y2 - tmp_y2) / 4;
		}
		else
		{
			men->j.zoomx /= 2;
			men->j.zoomy /= 2;
			men->j.imax /= 1.1;
			men->j.x1 = tmp_x - (men->j.x2 - men->j.x1);
			men->j.x2 = tmp_x + (men->j.x2 - tmp_x2);
			men->j.y1 = tmp_y - (men->j.y2 - men->j.y1);
			men->j.y2 = tmp_y + (men->j.y2 - tmp_y2);
		}
	}
	julia(men);
	return (1);
}
