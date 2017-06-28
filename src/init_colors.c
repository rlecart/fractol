/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 22:14:29 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/28 23:08:45 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_color_two(t_menu *men)
{
	if (!(men->s.pal->nx->nx->nx = (t_pal*)malloc(sizeof(t_pal))))
		exit(-1);
	men->s.pal->nx->nx->nx->col[0] = get_color(0, 51, 255, 0);
	men->s.pal->nx->nx->nx->col[1] = get_color(0, 102, 255, 0);
	men->s.pal->nx->nx->nx->col[2] = get_color(0, 153, 255, 0);
	men->s.pal->nx->nx->nx->col[3] = get_color(0, 204, 255, 0);
	men->s.pal->nx->nx->nx->col[4] = get_color(0, 255, 255, 0);
	men->s.pal->nx->nx->nx->before = men->s.pal->nx->nx;
	if (!(men->s.pal->nx->nx->nx->nx = (t_pal*)malloc(sizeof(t_pal))))
		exit(-1);
	men->s.pal->nx->nx->nx->nx->col[0] = get_color(0, 255, 51, 0);
	men->s.pal->nx->nx->nx->nx->col[1] = get_color(0, 255, 102, 0);
	men->s.pal->nx->nx->nx->nx->col[2] = get_color(0, 255, 153, 0);
	men->s.pal->nx->nx->nx->nx->col[3] = get_color(0, 255, 204, 0);
	men->s.pal->nx->nx->nx->nx->col[4] = get_color(0, 255, 255, 0);
	men->s.pal->nx->nx->nx->nx->before = men->s.pal->nx->nx->nx;
	if (!(men->s.pal->nx->nx->nx->nx->nx = (t_pal*)malloc(sizeof(t_pal))))
		exit(-1);
	men->s.pal->nx->nx->nx->nx->nx->col[0] = get_color(51, 255, 0, 0);
	men->s.pal->nx->nx->nx->nx->nx->col[1] = get_color(102, 255, 0, 0);
	men->s.pal->nx->nx->nx->nx->nx->col[2] = get_color(153, 255, 0, 0);
	men->s.pal->nx->nx->nx->nx->nx->col[3] = get_color(204, 255, 0, 0);
	men->s.pal->nx->nx->nx->nx->nx->col[4] = get_color(255, 255, 0, 0);
	men->s.pal->nx->nx->nx->nx->nx->before = men->s.pal->nx->nx->nx->nx;
	men->s.pal->nx->nx->nx->nx->nx->nx = NULL;
}

void	init_color_one(t_menu *men)
{
	if (!(men->s.pal = (t_pal*)malloc(sizeof(t_pal))))
		exit(-1);
	men->s.pal->col[0] = get_color(255, 51, 0, 0);
	men->s.pal->col[1] = get_color(255, 102, 0, 0);
	men->s.pal->col[2] = get_color(255, 153, 0, 0);
	men->s.pal->col[3] = get_color(255, 204, 0, 0);
	men->s.pal->col[4] = get_color(255, 255, 0, 0);
	men->s.pal->before = NULL;
	if (!(men->s.pal->nx = (t_pal*)malloc(sizeof(t_pal))))
		exit(-1);
	men->s.pal->nx->col[0] = get_color(255, 0, 51, 0);
	men->s.pal->nx->col[1] = get_color(255, 0, 102, 0);
	men->s.pal->nx->col[2] = get_color(255, 0, 153, 0);
	men->s.pal->nx->col[3] = get_color(255, 0, 204, 0);
	men->s.pal->nx->col[4] = get_color(255, 0, 255, 0);
	men->s.pal->nx->before = men->s.pal;
	if (!(men->s.pal->nx->nx = (t_pal*)malloc(sizeof(t_pal))))
		exit(-1);
	men->s.pal->nx->nx->col[0] = get_color(51, 0, 255, 0);
	men->s.pal->nx->nx->col[1] = get_color(102, 0, 255, 0);
	men->s.pal->nx->nx->col[2] = get_color(153, 0, 255, 0);
	men->s.pal->nx->nx->col[3] = get_color(204, 0, 255, 0);
	men->s.pal->nx->nx->col[4] = get_color(255, 0, 255, 0);
	men->s.pal->nx->nx->before = men->s.pal->nx;
	init_color_two(men);
}
