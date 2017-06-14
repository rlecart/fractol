/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:59:25 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/14 10:03:29 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

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
