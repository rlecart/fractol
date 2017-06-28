/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:59:48 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/28 23:24:31 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	ppj(t_menu *men)
{
	int		i;

	i = 0;
	if (men->j.x < men->j.image_x
			&& men->j.y < men->j.image_y
			&& men->j.x >= 0 && men->j.y > 0)
	{
		i = (men->j.y - 1) * men->j.image_x + men->j.x;
		((t_color*)men->j.img)[i] = men->j.pix;
	}
}

void	printj(t_menu *men)
{
	mlx_put_image_to_window(men->mlx, men->j.win, men->j.data, 0, 0);
}

void	julia_loop(t_menu *men, int tmp[5])
{
	men->j.z_r = men->j.x / men->j.zoomx + men->j.x1;
	men->j.z_i = men->j.y / men->j.zoomy + men->j.y1;
	men->j.i = 0;
	while ((men->j.z_r * men->j.z_r + men->j.z_i * men->j.z_i) < 4
			&& men->j.i < men->j.imax)
	{
		men->j.tmp = men->j.z_r;
		men->j.z_r = men->j.z_r * men->j.z_r - men->j.z_i * men->j.z_i
			+ men->j.c_r;
		men->j.z_i = 2 * men->j.z_i * men->j.tmp + men->j.c_i;
		men->j.i++;
	}
	if (men->j.i >= (int)men->j.imax)
		men->j.pix = get_color(0, 0, 0, 0);
	else
	{
		tmp[0] = men->j.i * 5 / (int)men->j.imax;
		tmp[1] = men->j.i * men->s.pal->col[tmp[0]].b / (int)men->j.imax;
		tmp[2] = men->j.i * men->s.pal->col[tmp[0]].g / (int)men->j.imax;
		tmp[3] = men->j.i * men->s.pal->col[tmp[0]].r / (int)men->j.imax;
		tmp[4] = men->j.i * men->s.pal->col[tmp[0]].a / (int)men->j.imax;
		men->j.pix = get_color(tmp[1], tmp[2], tmp[3], tmp[4]);
	}
}

void	julia(t_menu *men)
{
	if (!men->j.win)
		men->j.win = mlx_new_window(men->mlx, men->j.image_x, men->j.image_y,
				"Julia");
	mlx_mouse_hook(men->j.win, mouse_hook_julia, men);
	mlx_hook(men->j.win, 6, (1L << 6), mouse_motion_hook_julia, men);
	mlx_key_hook(men->j.win, key_hook_julia, men);
	men->j.x = 0;
	while (men->j.x < men->j.image_x)
	{
		men->j.y = 0;
		while (men->j.y < men->j.image_y)
		{
			julia_loop(men, (int[5]){0, 0, 0, 0, 0});
			ppj(men);
			men->j.y++;
		}
		men->j.x++;
	}
	printj(men);
}
