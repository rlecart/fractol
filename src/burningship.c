/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 04:00:10 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/28 23:26:48 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ppb(t_menu *men)
{
	int		i;

	i = 0;
	if (men->b.x < men->b.image_x
			&& men->b.y < men->b.image_y
			&& men->b.x >= 0 && men->b.y > 0)
	{
		i = (men->b.y - 1) * men->b.image_x + men->b.x;
		((t_color*)men->b.img)[i] = men->b.pix;
	}
}

void	printb(t_menu *men)
{
	mlx_put_image_to_window(men->mlx, men->b.win, men->b.data, 0, 0);
}

void	burningship_loop(t_menu *men, int tmp[5])
{
	men->b.c_r = men->b.x / men->b.zoomx + men->b.x1;
	men->b.c_i = men->b.y / men->b.zoomy + men->b.y1;
	men->b.z_r = 0;
	men->b.z_i = 0;
	men->b.i = 0;
	while ((men->b.z_r * men->b.z_r + men->b.z_i * men->b.z_i) < 4
			&& men->b.i < men->b.imax)
	{
		men->b.tmp = men->b.z_r;
		men->b.z_r = men->b.z_r * men->b.z_r - men->b.z_i * men->b.z_i
			+ men->b.c_r;
		men->b.z_i = 2 * fabsl(men->b.z_i * men->b.tmp) + men->b.c_i;
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
}

void	burningship(t_menu *men)
{
	if (!men->b.win)
		men->b.win = mlx_new_window(men->mlx, men->b.image_x, men->b.image_y,
				"Burningship");
	mlx_mouse_hook(men->b.win, mouse_hook_burningship, men);
	mlx_key_hook(men->b.win, key_hook_burningship, men);
	men->b.x = 0;
	while (men->b.x < men->b.image_x)
	{
		men->b.y = 0;
		while (men->b.y < men->b.image_y)
		{
			burningship_loop(men, (int[5]){0, 0, 0, 0, 0});
			ppb(men);
			men->b.y++;
		}
		men->b.x++;
	}
	printb(men);
}
