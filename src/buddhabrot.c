/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 04:00:10 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/14 03:34:26 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		key_hook_buddhabrot(int key, void *param)
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
		buddhabrot(men);
	}
	return (1);
}

int		mouse_hook_buddhabrot(int button, int x, int y, void *param)
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
	buddhabrot(men);
	return (1);
}

void	ppb(t_menu *men)
{
	int		i;

	i = 0;
	if (men->b.x < men->b.image_x && men->b.y < men->b.image_y && men->b.x >= 0 && men->b.y > 0)
	{
		i = (men->b.y - 1) * men->b.image_x + men->b.x;
		((t_color*)men->b.img)[i] = men->b.pix;
	}
}

void	printb(t_menu *men)
{
	mlx_put_image_to_window(men->mlx, men->b.win, men->b.data, 0, 0);
}

void	buddhabrot(t_menu *men)
{
	int		tmp[5];

	if (!men->b.win)
		men->b.win = mlx_new_window(men->mlx, men->b.image_x, men->b.image_y, "Buddhabrot");
	mlx_mouse_hook(men->b.win, mouse_hook_buddhabrot, men);
	mlx_key_hook(men->b.win, key_hook_buddhabrot, men);
	men->b.x = 0;
	while (men->b.x < men->b.image_x)
	{
		men->b.y = 0;
		while (men->b.y < men->b.image_y)
		{
			men->b.c_r = 0.285;
			men->b.c_i = 0.01;
			men->b.z_r = men->b.x / men->b.zoomx + men->b.x1;
			men->b.z_i = men->b.y / men->b.zoomy + men->b.y1;
			men->b.i = 0;
			while ((men->b.z_r * men->b.z_r + men->b.z_i * men->b.z_i) < 4 && men->b.i < men->b.imax)
			{
				men->b.tmp = men->b.z_r;
				men->b.z_r = men->b.z_r * men->b.z_r - men->b.z_i * men->b.z_i + men->b.c_r;
				men->b.z_i = 2 * men->b.z_i * men->b.tmp + men->b.c_i;
				men->b.i++;
			}
			if (men->b.i >= (int)men->b.imax)
				men->b.pix = get_color(0, 0, 0, 0);
			else
			{
				tmp[0] = men->b.i * 5 / (int)men->b.imax;
				tmp[1] = men->b.i * men->s.pal->col[tmp[0]].b / (int)men->b.imax;
				tmp[2] = men->b.i * men->s.pal->col[tmp[0]].g / (int)men->b.imax;
				tmp[3] = men->b.i * men->s.pal->col[tmp[0]].r / (int)men->b.imax;
				tmp[4] = men->b.i * men->s.pal->col[tmp[0]].a / (int)men->b.imax;
				men->b.pix = get_color(tmp[1], tmp[2], tmp[3], tmp[4]);
			}
			ppb(men);
			men->b.y++;
		}
		men->b.x++;
	}
	printb(men);
}
