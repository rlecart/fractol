/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 23:18:59 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/29 00:31:34 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		mouse_hook_settings(int b, int x, int y, void *param)
{
	void	*mlx;
	t_menu	*men;

	men = (t_menu*)param;
	mlx = men->mlx;
	if (b == 1)
	{
		mlx_destroy_image(men->mlx, men->s.data);
		if (men->s.choice == 1)
			tab_one(x, y, men);
		else if (men->s.choice == 2)
			tab_two(x, y, men);
		else if (men->s.choice == 3)
			tab_three(x, y, men);
		mlx_put_image_to_window(mlx, men->s.win, men->s.data, 0, 0);
		mlx_put_image_to_window(mlx, men->s.win, men->s.button, 374, 179);
		mlx_put_image_to_window(mlx, men->s.win, men->s.colors, 50, 258);
		mlx_put_image_to_window(mlx, men->s.win, men->s.first, 56, 439);
	}
	return (1);
}

int		mouse_motion_hook_settings(int x, int y, void *param)
{
	void	*mlx;
	t_menu	*men;

	men = (t_menu*)param;
	mlx = men->mlx;
	mlx_destroy_image(men->mlx, men->s.data);
	if (men->s.choice == 1)
		tab_motion_one(x, y, men);
	else if (men->s.choice == 2)
		tab_motion_two(x, y, men);
	else if (men->s.choice == 3)
		tab_motion_three(x, y, men);
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
		mouse_hook_settings(1, 0, 0, men);
		menu(men, 5);
	}
	else if (key == LEFT)
	{
		if (men->s.choice > 1)
			men->s.choice--;
		mouse_hook_settings(1, 0, 0, men);
		menu(men, 5);
	}
	return (1);
}
