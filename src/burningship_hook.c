/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 09:57:32 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/29 00:07:14 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	key_hook_two(int key, t_menu *men)
{
	if (key == RIGHT)
		men->b.y1++;
	else if (key == LEFT)
		men->b.y1--;
	else if (key == UP)
		men->b.x1--;
	else if (key == DOWN)
		men->b.x1++;
	else if (key == PLUS)
		men->b.pom = 1;
	else if (key == MINUS)
		men->b.pom = -1;
	else if (key == BACKSPACE)
		roll_palette(&men->s.pal);
	else if (key == ENTER)
	{
		destroy_window(men);
		init_burningship(&men->b, men->mlx);
	}
	burningship(men);
}

int		key_hook_burningship(int key, void *param)
{
	t_menu		*men;

	men = ((t_menu*)param);
	if (key == ESC)
		menu(men, 4);
	else
		key_hook_two(key, men);
	return (1);
}

void	bship_zoom(t_menu *men, long double tmp_x[2], long double tmp_y[2])
{
	if (men->b.pom == 1)
	{
		men->b.zoomx *= 2;
		men->b.zoomy *= 2;
		men->b.imax *= 1.15;
		men->b.x1 = tmp_x[0] - (men->b.x2 - men->b.x1) / 4;
		men->b.x2 = tmp_x[0] + (men->b.x2 - tmp_x[1]) / 4;
		men->b.y1 = tmp_y[0] - (men->b.y2 - men->b.y1) / 4;
		men->b.y2 = tmp_y[0] + (men->b.y2 - tmp_y[1]) / 4;
	}
	else
	{
		men->b.zoomx /= 2;
		men->b.zoomy /= 2;
		men->b.imax /= 1.15;
		men->b.x1 = tmp_x[0] - (men->b.x2 - men->b.x1);
		men->b.x2 = tmp_x[0] + (men->b.x2 - tmp_x[1]);
		men->b.y1 = tmp_y[0] - (men->b.y2 - men->b.y1);
		men->b.y2 = tmp_y[0] + (men->b.y2 - tmp_y[1]);
	}
}

int		mouse_hook_burningship(int button, int x, int y, void *param)
{
	long double	tmp_x[2];
	long double	tmp_y[2];
	t_menu		*men;

	men = ((t_menu*)param);
	if (button == 1 || button == 4 || button == 5)
	{
		if (button == 4)
			men->b.pom = 1;
		else if (button == 5)
			men->b.pom = -1;
		tmp_x[0] = men->b.x1 + x * (men->b.x2 - men->b.x1) / men->b.image_x;
		tmp_y[0] = men->b.y1 + y * (men->b.y2 - men->b.y1) / men->b.image_y;
		tmp_x[1] = men->b.x1;
		tmp_y[1] = men->b.y1;
		bship_zoom(men, tmp_x, tmp_y);
	}
	burningship(men);
	return (1);
}
