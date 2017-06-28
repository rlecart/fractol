/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:43:40 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/28 23:09:46 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_mandelbrot(t_mandelbrot *m, void *mlx)
{
	int		i;

	m->win = NULL;
	m->pix = get_color(255, 255, 255, 0);
	m->zoom = 100;
	m->x1 = -2.0;
	m->x2 = 0.5;
	m->y1 = -1.1;
	m->y2 = 1.1;
	m->pom = 1;
	m->imax = 50.0;
	find_ratio_m(m, 270, 240);
	m->zoomx = m->image_x / (m->x2 - m->x1);
	m->zoomy = m->image_y / (m->y2 - m->y1);
	m->data = mlx_new_image(mlx, m->image_x, m->image_y);
	m->img = mlx_get_data_addr(m->data, &i, &i, &i);
}

void	init_julia(t_julia *j, void *mlx)
{
	int		i;

	j->win = NULL;
	j->pix = get_color(255, 255, 255, 0);
	j->x1 = -1;
	j->x2 = 1;
	j->y1 = -1.2;
	j->y2 = 1.2;
	j->pom = 1;
	j->imax = 150;
	j->c_r = 0.285;
	j->c_i = 0.01;
	j->motion = 0;
	find_ratio_j(j, 240, 240);
	j->zoomx = j->image_x / (j->x2 - j->x1);
	j->zoomy = j->image_y / (j->y2 - j->y1);
	j->data = mlx_new_image(mlx, j->image_x, j->image_y);
	j->img = mlx_get_data_addr(j->data, &i, &i, &i);
}

void	init_burningship(t_burningship *b, void *mlx)
{
	int		i;

	b->win = NULL;
	b->pix = get_color(255, 255, 255, 0);
	b->zoom = 100;
	b->x1 = -2.0;
	b->x2 = 0.5;
	b->y1 = -1.1;
	b->y2 = 1.1;
	b->pom = 1;
	b->imax = 50.0;
	find_ratio_b(b, 270, 240);
	b->zoomx = b->image_x / (b->x2 - b->x1);
	b->zoomy = b->image_y / (b->y2 - b->y1);
	b->data = mlx_new_image(mlx, b->image_x, b->image_y);
	b->img = mlx_get_data_addr(b->data, &i, &i, &i);
}

void	init_menu_settings(t_menu *men)
{
	int		i;
	void	*mlx;

	men->mlx = mlx_init();
	mlx = men->mlx;
	men->win = NULL;
	men->s.win = NULL;
	men->s.choice = 1;
	men->s.bolm = 1;
	men->s.bolj = 1;
	men->s.bolb = 1;
	men->s.button = mlx_xpm_file_to_image(mlx, "img/xpm/dis.xpm", &i, &i);
	men->s.colors = mlx_xpm_file_to_image(mlx, "img/xpm/dis_cp.xpm", &i, &i);
	men->s.first = mlx_xpm_file_to_image(mlx, "img/xpm/dis_bup.xpm", &i, &i);
	init_color_one(men);
}

void	init(t_menu *men)
{
	init_menu_settings(men);
	init_mandelbrot(&men->m, men->mlx);
	init_julia(&men->j, men->mlx);
	init_burningship(&men->b, men->mlx);
}
