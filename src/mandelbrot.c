/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:59:25 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/08 21:00:07 by rlecart          ###   ########.fr       */
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

void	ppm(t_menu *men)
{
	int		i;

	i = 0;
	if (men->m.x < men->m.image_x && men->m.y < men->m.image_y && men->m.x >= 0 && men->m.y > 0)
	{
		i = (men->m.y - 1) * men->m.image_x + men->m.x;
		((t_color*)men->m.img)[i] = men->m.pix;
	}
}

void	printm(t_menu *men)
{
	mlx_put_image_to_window(men->mlx, men->m.win, men->m.data, 0, 0);
}

void	mandelbrot(t_menu *men)
{
	int		tmp[5];

	if (!men->m.win)
		men->m.win = mlx_new_window(men->mlx, men->m.image_x, men->m.image_y, "Mandelbrot");
	mlx_mouse_hook(men->m.win, mouse_hook_mandelbrot, men);
	mlx_key_hook(men->m.win, key_hook_mandelbrot, men);
	men->m.x = 0;
	while (men->m.x < men->m.image_x)
	{
		men->m.y = 0;
		while (men->m.y < men->m.image_y)
		{
			men->m.c_r = men->m.x / men->m.zoomx + men->m.x1;
			men->m.c_i = men->m.y / men->m.zoomy + men->m.y1;
			men->m.z_r = 0;
			men->m.z_i = 0;
			men->m.i = 0;
			while ((men->m.z_r * men->m.z_r + men->m.z_i * men->m.z_i) < 4 && men->m.i < men->m.imax)
			{
				men->m.tmp = men->m.z_r;
				men->m.z_r = men->m.z_r * men->m.z_r - men->m.z_i * men->m.z_i + men->m.c_r;
				men->m.z_i = 2 * men->m.z_i * men->m.tmp + men->m.c_i;
				men->m.i++;
			}
			if (men->m.i >= (int)men->m.imax)
				men->m.pix = get_color(0, 0, 0, 0);
			else
			{
				tmp[0] = men->m.i * 5 / (int)men->m.imax;
				tmp[1] = men->m.i * men->s.pal->col[tmp[0]].b / (int)men->m.imax;
				tmp[2] = men->m.i * men->s.pal->col[tmp[0]].g / (int)men->m.imax;
				tmp[3] = men->m.i * men->s.pal->col[tmp[0]].r / (int)men->m.imax;
				tmp[4] = men->m.i * men->s.pal->col[tmp[0]].a / (int)men->m.imax;
				men->m.pix = get_color(tmp[1], tmp[2], tmp[3], tmp[4]);
			}
			ppm(men);
			men->m.y++;
		}
		men->m.x++;
	}
	printm(men);
}
