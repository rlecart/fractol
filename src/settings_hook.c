/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 23:18:59 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/20 00:16:16 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	exec_b(t_menu *men, int x, int y, int *bol)
{
	int		i;
	void	*m;

	m = men->mlx;
	if (x >= 384 && x <= 639 && y >= 179 && y <= 236)
		*bol *= -1;
	if (*bol == -1)
	{
		mlx_destroy_image(men->mlx, men->s.button);
		mlx_destroy_image(men->mlx, men->s.colors);
		mlx_destroy_image(men->mlx, men->s.first);
		men->s.button = mlx_xpm_file_to_image(m, "img/xpm/en.xpm", &i, &i);
		men->s.colors = mlx_xpm_file_to_image(m, "img/xpm/en_cp.xpm", &i, &i);
		men->s.first = mlx_xpm_file_to_image(m, "img/xpm/en_bup.xpm", &i, &i);
	}
	else if (*bol == 1)
	{
		mlx_destroy_image(men->mlx, men->s.button);
		mlx_destroy_image(men->mlx, men->s.colors);
		mlx_destroy_image(men->mlx, men->s.first);
		men->s.button = mlx_xpm_file_to_image(m, "img/xpm/dis.xpm", &i, &i);
		men->s.colors = mlx_xpm_file_to_image(m, "img/xpm/dis_cp.xpm", &i, &i);
		men->s.first = mlx_xpm_file_to_image(m, "img/xpm/dis_bup.xpm", &i, &i);
	}
}

int		mouse_hook_settings(int b, int x, int y, void *param)
{
	int		i;
	void	*mlx;
	t_menu	*men;

	men = (t_menu*)param;
	mlx = men->mlx;
	if (b == 1)
	{
		mlx_destroy_image(men->mlx, men->s.data);
		if (men->s.choice == 1)
		{
			if (x >= 429 && x <= 592 && y >= 117 && y <= 145 && (men->s.choice = 2))
			{
				men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_jon.xpm", &i, &i);
				exec_b(men, x, y, &men->s.bolj);
			}
			else if (x >= 592 && x <= 771 && y >= 117 && y <= 145 && (men->s.choice = 3))
			{
				men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_bon.xpm", &i, &i);
				exec_b(men, x, y, &men->s.bolb);
			}
			else
			{
				men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_mon.xpm", &i, &i);
				exec_b(men, x, y, &men->s.bolm);
			}
		}
		else if (men->s.choice == 2)
		{
			if (x >= 252 && x <= 429 && y >= 117 && y <= 145 && (men->s.choice = 1))
			{
				men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_mon.xpm", &i, &i);
				exec_b(men, x, y, &men->s.bolm);
			}
			else if (x >= 592 && x <= 771 && y >= 117 && y <= 145 && (men->s.choice = 3))
			{
				men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_bon.xpm", &i, &i);
				exec_b(men, x, y, &men->s.bolb);
			}
			else
			{
				men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_jon.xpm", &i, &i);
				exec_b(men, x, y, &men->s.bolj);
			}
		}
		else if (men->s.choice == 3)
		{
			if (x >= 252 && x <= 429 && y >= 117 && y <= 145 && (men->s.choice = 1))
			{
				men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_mon.xpm", &i, &i);
				exec_b(men, x, y, &men->s.bolm);
			}
			else if (x >= 429 && x <= 592 && y >= 117 && y <= 145 && (men->s.choice = 2))
			{
				men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_jon.xpm", &i, &i);
				exec_b(men, x, y, &men->s.bolj);
			}
			else
			{
				men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_bon.xpm", &i, &i);
				exec_b(men, x, y, &men->s.bolb);
			}
		}
		mlx_put_image_to_window(mlx, men->s.win, men->s.data, 0, 0);
		mlx_put_image_to_window(mlx, men->s.win, men->s.button, 374, 179);
		mlx_put_image_to_window(mlx, men->s.win, men->s.colors, 50, 258);
		mlx_put_image_to_window(mlx, men->s.win, men->s.first, 56, 439);
	}
	return (1);
}

int		mouse_motion_hook_settings(int x, int y, void *param)
{
	int		i;
	void	*mlx;
	t_menu	*men;

	men = (t_menu*)param;
	mlx = men->mlx;
	mlx_destroy_image(men->mlx, men->s.data);
	if (men->s.choice == 1)
	{
		if (x >= 429 && x <= 592 && y >= 117 && y <= 145)
			men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_mon1.xpm", &i, &i);
		else if (x >= 592 && x <= 771 && y >= 117 && y <= 145)
			men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_mon2.xpm", &i, &i);
		else
			men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_mon.xpm", &i, &i);
	}
	else if (men->s.choice == 2)
	{
		if (x >= 252 && x <= 429 && y >= 117 && y <= 145)
			men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_jon1.xpm", &i, &i);
		else if (x >= 592 && x <= 771 && y >= 117 && y <= 145)
			men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_jon2.xpm", &i, &i);
		else
			men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_jon.xpm", &i, &i);
	}
	else if (men->s.choice == 3)
	{
		if (x >= 252 && x <= 429 && y >= 117 && y <= 145)
			men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_bon1.xpm", &i, &i);
		else if (x >= 429 && x <= 592 && y >= 117 && y <= 145)
			men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_bon2.xpm", &i, &i);
		else
			men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_bon.xpm", &i, &i);
	}
	mlx_put_image_to_window(mlx, men->s.win, men->s.data, 0, 0);
	mlx_put_image_to_window(mlx, men->s.win, men->s.button, 374, 179);
	mlx_put_image_to_window(mlx, men->s.win, men->s.colors, 50, 258);
	mlx_put_image_to_window(mlx, men->s.win, men->s.first, 56, 439);
	return (1);
}

int		key_hook_settings(int key, void *param)
{
	t_menu	*men;

	men = ((t_menu*)param);
	if (key == ESC)
	{
		men->s.choice = 1;
		exec_b(men, 0, 0, &men->s.bolm);
		menu(men, 4);
	}
	else if (key == RIGHT)
	{
		if (men->s.choice < 3)
			men->s.choice++;
		menu(men, 5);
	}
	else if (key == LEFT)
	{
		if (men->s.choice > 1)
			men->s.choice--;
		menu(men, 5);
	}
	return (1);
}
