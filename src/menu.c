/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:36:49 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/14 17:39:06 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	destroy_window(t_menu *men)
{
	if (men->m.win)
	{
		mlx_destroy_window(men->mlx, men->m.win);
		men->m.win = NULL;
	}
	if (men->j.win)
	{
		mlx_destroy_window(men->mlx, men->j.win);
		men->j.win = NULL;
	}
	if (men->b.win)
	{
		mlx_destroy_window(men->mlx, men->b.win);
		men->b.win = NULL;
	}
	if (men->s.win)
	{
		mlx_destroy_window(men->mlx, men->s.win);
		men->s.win = NULL;
	}
	if (men->win)
	{
		mlx_destroy_window(men->mlx, men->win);
		men->win = NULL;
	}
}

void	menu(t_menu *men, int choice)
{
	int		i;

	destroy_window(men);
	if (choice == 1)
		mandelbrot(men);
	else if (choice == 2)
		julia(men);
	else if (choice == 3)
		burningship(men);
	else if (choice == 4)
	{
		men->win = mlx_new_window(men->mlx, 1024, 768, "Menu");
		men->data = mlx_xpm_file_to_image(men->mlx, "img/xpm/menu.xpm", &i, &i);
		mlx_put_image_to_window(men->mlx, men->win, men->data, 0, 0);
		mlx_key_hook(men->win, key_hook_menu, men);
		mlx_hook(men->win, 4, (1L << 2), mouse_hook_menu, men);
		mlx_hook(men->win, 5, (1L << 2), mouse_release_hook_menu, men);
		mlx_hook(men->win, 6, (1L << 6), mouse_motion_hook_menu, men);
	}
	else if (choice == 5)
		settings(men);
	else
		exit(0);
}
