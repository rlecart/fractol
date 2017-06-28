/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 00:19:35 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/29 00:33:19 by rlecart          ###   ########.fr       */
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

void	tab_one(int x, int y, t_menu *men)
{
	int		i;
	void	*mlx;

	mlx = men->mlx;
	if (x >= 429 && x <= 592 && y >= 117 && y <= 145 && (men->s.choice = 2))
	{
		men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_jon.xpm", &i, &i);
		exec_b(men, x, y, &men->s.bolj);
	}
	else if (x >= 592 && x <= 771 && y >= 117 && y <= 145
			&& (men->s.choice = 3))
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

void	tab_two(int x, int y, t_menu *men)
{
	int		i;
	void	*mlx;

	mlx = men->mlx;
	if (x >= 252 && x <= 429 && y >= 117 && y <= 145 && (men->s.choice = 1))
	{
		men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_mon.xpm", &i, &i);
		exec_b(men, x, y, &men->s.bolm);
	}
	else if (x >= 592 && x <= 771 && y >= 117 && y <= 145
			&& (men->s.choice = 3))
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

void	tab_three(int x, int y, t_menu *men)
{
	int		i;
	void	*mlx;

	mlx = men->mlx;
	if (x >= 252 && x <= 429 && y >= 117 && y <= 145 && (men->s.choice = 1))
	{
		men->s.data = mlx_xpm_file_to_image(mlx, "img/xpm/set_mon.xpm", &i, &i);
		exec_b(men, x, y, &men->s.bolm);
	}
	else if (x >= 429 && x <= 592 && y >= 117 && y <= 145
			&& (men->s.choice = 2))
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
