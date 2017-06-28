/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_tab_motion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 00:26:34 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/29 00:32:51 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	tab_motion_one(int x, int y, t_menu *men)
{
	int		i;
	void	*m;

	m = men->mlx;
	if (x >= 429 && x <= 592 && y >= 117 && y <= 145)
		men->s.data = mlx_xpm_file_to_image(m, "img/xpm/set_mon1.xpm", &i, &i);
	else if (x >= 592 && x <= 771 && y >= 117 && y <= 145)
		men->s.data = mlx_xpm_file_to_image(m, "img/xpm/set_mon2.xpm", &i, &i);
	else
		men->s.data = mlx_xpm_file_to_image(m, "img/xpm/set_mon.xpm", &i, &i);
}

void	tab_motion_two(int x, int y, t_menu *men)
{
	int		i;
	void	*m;

	m = men->mlx;
	if (x >= 252 && x <= 429 && y >= 117 && y <= 145)
		men->s.data = mlx_xpm_file_to_image(m, "img/xpm/set_jon1.xpm", &i, &i);
	else if (x >= 592 && x <= 771 && y >= 117 && y <= 145)
		men->s.data = mlx_xpm_file_to_image(m, "img/xpm/set_jon2.xpm", &i, &i);
	else
		men->s.data = mlx_xpm_file_to_image(m, "img/xpm/set_jon.xpm", &i, &i);
}

void	tab_motion_three(int x, int y, t_menu *men)
{
	int		i;
	void	*m;

	m = men->mlx;
	if (x >= 252 && x <= 429 && y >= 117 && y <= 145)
		men->s.data = mlx_xpm_file_to_image(m, "img/xpm/set_bon1.xpm", &i, &i);
	else if (x >= 429 && x <= 592 && y >= 117 && y <= 145)
		men->s.data = mlx_xpm_file_to_image(m, "img/xpm/set_bon2.xpm", &i, &i);
	else
		men->s.data = mlx_xpm_file_to_image(m, "img/xpm/set_bon.xpm", &i, &i);
}
