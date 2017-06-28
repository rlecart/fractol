/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 03:22:32 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/29 00:16:46 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		mouse_release_hook_menu(int b, int x, int y, void *param)
{
	int		i;
	int		c;
	void	*mlx;
	t_menu	*men;

	men = (t_menu*)param;
	mlx = men->mlx;
	mlx_destroy_image(men->mlx, men->data);
	c = 4;
	if (b == 1 && x >= 270 && x <= 753 && y >= 290 && y <= 340 && (c = 1))
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_mov.xpm", &i, &i);
	else if (b == 1 && x >= 270 && x <= 753 && y >= 382 && y <= 433 && (c = 2))
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_jov.xpm", &i, &i);
	else if (b == 1 && x >= 270 && x <= 753 && y >= 473 && y <= 524 && (c = 3))
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_bov.xpm", &i, &i);
	else if (b == 1 && x >= 270 && x <= 493 && y >= 566 && y <= 616 && (c = 5))
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_sov.xpm", &i, &i);
	else if (b == 1 && x >= 530 && x <= 753 && y >= 566 && y <= 616 && (c = 6))
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_qov.xpm", &i, &i);
	else
		men->data = mlx_xpm_file_to_image(men->mlx, "img/xpm/menu.xpm", &i, &i);
	mlx_put_image_to_window(men->mlx, men->win, men->data, 0, 0);
	menu(men, c);
	return (1);
}

int		mouse_hook_menu(int b, int x, int y, void *param)
{
	int		i;
	void	*mlx;
	t_menu	*men;

	men = (t_menu*)param;
	mlx = men->mlx;
	mlx_destroy_image(men->mlx, men->data);
	if (b == 1 && x >= 270 && x <= 753 && y >= 290 && y <= 340)
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_mon.xpm", &i, &i);
	else if (b == 1 && x >= 270 && x <= 753 && y >= 382 && y <= 433)
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_jon.xpm", &i, &i);
	else if (b == 1 && x >= 270 && x <= 753 && y >= 473 && y <= 524)
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_bon.xpm", &i, &i);
	else if (b == 1 && x >= 270 && x <= 493 && y >= 566 && y <= 616)
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_son.xpm", &i, &i);
	else if (b == 1 && x >= 530 && x <= 753 && y >= 566 && y <= 616)
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_qon.xpm", &i, &i);
	else
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu.xpm", &i, &i);
	mlx_put_image_to_window(men->mlx, men->win, men->data, 0, 0);
	return (1);
}

int		mouse_motion_hook_menu(int x, int y, void *param)
{
	int		i;
	void	*mlx;
	t_menu	*men;

	men = (t_menu*)param;
	mlx = men->mlx;
	mlx_destroy_image(men->mlx, men->data);
	if (x >= 270 && x <= 753 && y >= 290 && y <= 340)
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_mov.xpm", &i, &i);
	else if (x >= 270 && x <= 753 && y >= 382 && y <= 433)
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_jov.xpm", &i, &i);
	else if (x >= 270 && x <= 753 && y >= 473 && y <= 524)
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_bov.xpm", &i, &i);
	else if (x >= 270 && x <= 493 && y >= 566 && y <= 616)
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_sov.xpm", &i, &i);
	else if (x >= 530 && x <= 753 && y >= 566 && y <= 616)
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu_qov.xpm", &i, &i);
	else
		men->data = mlx_xpm_file_to_image(mlx, "img/xpm/menu.xpm", &i, &i);
	mlx_put_image_to_window(men->mlx, men->win, men->data, 0, 0);
	return (1);
}

int		key_hook_menu(int key, void *param)
{
	t_menu	*men;

	men = ((t_menu*)param);
	if (key == ESC)
		exit(0);
	else if (key == KEY_1)
		menu(men, 1);
	else if (key == KEY_2)
		menu(men, 2);
	else if (key == KEY_3)
		menu(men, 3);
	return (1);
}
