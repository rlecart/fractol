/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 22:58:08 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/28 23:28:05 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	roll_palette(t_pal **pal)
{
	if ((*pal)->nx)
		(*pal) = (*pal)->nx;
	else
		while ((*pal)->before)
			(*pal) = (*pal)->before;
}

void	settings(t_menu *men)
{
	int		i;
	void	*mlx;

	mlx = men->mlx;
	destroy_window(men);
	men->s.win = mlx_new_window(men->mlx, 1024, 768, "Settings");
	if (men->s.choice == 1)
		men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_mon.xpm", &i, &i);
	else if (men->s.choice == 2)
		men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_jon.xpm", &i, &i);
	else
		men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_bon.xpm", &i, &i);
	mlx_put_image_to_window(men->mlx, men->s.win, men->s.data, 0, 0);
	mlx_put_image_to_window(men->mlx, men->s.win, men->s.button, 374, 179);
	mlx_put_image_to_window(men->mlx, men->s.win, men->s.colors, 50, 258);
	mlx_put_image_to_window(men->mlx, men->s.win, men->s.first, 56, 439);
	mlx_key_hook(men->s.win, key_hook_settings, men);
	mlx_hook(men->s.win, 4, (1L << 2), mouse_hook_settings, men);
	mlx_hook(men->s.win, 6, (1L << 6), mouse_motion_hook_settings, men);
}
