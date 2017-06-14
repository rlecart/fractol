/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:43:40 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/09 13:59:23 by rlecart          ###   ########.fr       */
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
	find_ratio_j(j, 240, 240);
	j->zoomx = j->image_x / (j->x2 - j->x1);
	j->zoomy = j->image_y / (j->y2 - j->y1);
	j->data = mlx_new_image(mlx, j->image_x, j->image_y);
	j->img = mlx_get_data_addr(j->data, &i, &i, &i);
}

void	init_buddhabrot(t_buddhabrot *b, void *mlx)
{
	int		i;

	b->win = NULL;
	b->pix = get_color(255, 255, 255, 0);
	b->x1 = -2.1;
	b->x2 = 0.6;
	b->y1 = -1.2;
	b->y2 = 1.2;
	b->pom = 1;
	b->imax = 150;
	find_ratio_b(b, 240, 240);
	b->zoomx = b->image_x / (b->x2 - b->x1);
	b->zoomy = b->image_y / (b->y2 - b->y1);
	b->data = mlx_new_image(mlx, b->image_x, b->image_y);
	b->img = mlx_get_data_addr(b->data, &i, &i, &i);
}

void	init_menu_settings(t_menu *men)
{
	int		i;

	men->mlx = mlx_init();
	men->win = NULL;
	men->s.data = mlx_new_image(men->mlx, 1024, 768);
	men->s.img = mlx_get_data_addr(men->s.data, &i, &i, &i);
	men->s.win = NULL;
	men->s.choice = 1;
	if (!(men->s.pal = (t_pal*)malloc(sizeof(t_pal))))
		exit(-1);
	men->s.pal->col[0] = get_color(255, 51, 0, 0);
	men->s.pal->col[1] = get_color(255, 102, 0, 0);
	men->s.pal->col[2] = get_color(255, 153, 0, 0);
	men->s.pal->col[3] = get_color(255, 204, 0, 0);
	men->s.pal->col[4] = get_color(255, 255, 0, 0);
	men->s.pal->before = NULL;
	if (!(men->s.pal->next = (t_pal*)malloc(sizeof(t_pal))))
		exit(-1);
	men->s.pal->next->col[0] = get_color(255, 0, 51, 0);
	men->s.pal->next->col[1] = get_color(255, 0, 102, 0);
	men->s.pal->next->col[2] = get_color(255, 0, 153, 0);
	men->s.pal->next->col[3] = get_color(255, 0, 204, 0);
	men->s.pal->next->col[4] = get_color(255, 0, 255, 0);
	men->s.pal->next->before = men->s.pal;
	if (!(men->s.pal->next->next = (t_pal*)malloc(sizeof(t_pal))))
		exit(-1);
	men->s.pal->next->next->col[0] = get_color(51, 0, 255, 0);
	men->s.pal->next->next->col[1] = get_color(102, 0, 255, 0);
	men->s.pal->next->next->col[2] = get_color(153, 0, 255, 0);
	men->s.pal->next->next->col[3] = get_color(204, 0, 255, 0);
	men->s.pal->next->next->col[4] = get_color(255, 0, 255, 0);
	men->s.pal->next->next->before = men->s.pal->next;
	if (!(men->s.pal->next->next->next = (t_pal*)malloc(sizeof(t_pal))))
		exit(-1);
	men->s.pal->next->next->next->col[0] = get_color(0, 51, 255, 0);
	men->s.pal->next->next->next->col[1] = get_color(0, 102, 255, 0);
	men->s.pal->next->next->next->col[2] = get_color(0, 153, 255, 0);
	men->s.pal->next->next->next->col[3] = get_color(0, 204, 255, 0);
	men->s.pal->next->next->next->col[4] = get_color(0, 255, 255, 0);
	men->s.pal->next->next->next->before = men->s.pal->next->next;
	if (!(men->s.pal->next->next->next->next = (t_pal*)malloc(sizeof(t_pal))))
		exit(-1);
	men->s.pal->next->next->next->next->col[0] = get_color(0, 255, 51, 0);
	men->s.pal->next->next->next->next->col[1] = get_color(0, 255, 102, 0);
	men->s.pal->next->next->next->next->col[2] = get_color(0, 255, 153, 0);
	men->s.pal->next->next->next->next->col[3] = get_color(0, 255, 204, 0);
	men->s.pal->next->next->next->next->col[4] = get_color(0, 255, 255, 0);
	men->s.pal->next->next->next->next->before = men->s.pal->next->next->next;
	if (!(men->s.pal->next->next->next->next->next = (t_pal*)malloc(sizeof(t_pal))))
		exit(-1);
	men->s.pal->next->next->next->next->next->col[0] = get_color(51, 255, 0, 0);
	men->s.pal->next->next->next->next->next->col[1] = get_color(102, 255, 0, 0);
	men->s.pal->next->next->next->next->next->col[2] = get_color(153, 255, 0, 0);
	men->s.pal->next->next->next->next->next->col[3] = get_color(204, 255, 0, 0);
	men->s.pal->next->next->next->next->next->col[4] = get_color(255, 255, 0, 0);
	men->s.pal->next->next->next->next->next->before = men->s.pal->next->next->next->next;
	men->s.pal->next->next->next->next->next->next = NULL;
}

void	init(t_menu *men)
{
	init_menu_settings(men);
	init_mandelbrot(&men->m, men->mlx);
	init_julia(&men->j, men->mlx);
	init_buddhabrot(&men->b, men->mlx);
}
