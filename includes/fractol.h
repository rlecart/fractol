/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:04:41 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/20 00:52:42 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <../graphics/includes/graphics.h>

typedef struct		s_julia
{
	int				i;
	int				x;
	int				y;
	int				motion;
	char			*img;
	void			*win;
	void			*data;
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	long double		tmp;
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	long double		pom;
	long double		imax;
	long double		zoomx;
	long double		zoomy;
	long double		image_x;
	long double		image_y;
	t_color			pix;
}					t_julia;

typedef struct		s_mandelbrot
{
	int				i;
	int				x;
	int				y;
	char			*img;
	void			*win;
	void			*data;
	long double		tmp;
	long double		zoom;
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	long double		pom;
	long double		imax;
	long double		zoomx;
	long double		zoomy;
	long double		image_x;
	long double		image_y;
	t_color			pix;
}					t_mandelbrot;

typedef struct		s_burningship
{
	int				i;
	int				x;
	int				y;
	char			*img;
	void			*win;
	void			*data;
	long double		tmp;
	long double		zoom;
	long double		x1;
	long double		x2;
	long double		y1;
	long double		y2;
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	long double		pom;
	long double		imax;
	long double		zoomx;
	long double		zoomy;
	long double		image_x;
	long double		image_y;
	t_color			pix;
}					t_burningship;

typedef struct		s_pal
{
	t_color			col[5];
	struct s_pal	*before;
	struct s_pal	*next;
}					t_pal;

typedef struct		s_settings
{
	int				bolm;
	int				bolj;
	int				bolb;
	int				choice;
	t_pal			*pal;
	void			*win;
	void			*data;
	void			*button;
	void			*colors;
	void			*first;
}					t_settings;

typedef struct		s_menu
{
	char			*img;
	void			*data;
	void			*mlx;
	void			*win;
	t_julia			j;
	t_mandelbrot	m;
	t_burningship	b;
	t_settings		s;
}					t_menu;

void				init(t_menu *men);
void				roll_palette(t_pal **pal);
void				destroy_window(t_menu *men);

void				menu(t_menu *men, int choice);
int					key_hook_menu(int key, void *param);
int					mouse_motion_hook(int x, int y, void *param);
int					mouse_motion_hook_menu(int x, int y, void *param);
int					mouse_hook_menu(int button, int x, int y, void *param);
int					mouse_release_hook_menu(int b, int x, int y, void *param);

void				settings(t_menu *men);
int					key_hook_settings(int key, void *param);
int					mouse_motion_hook_settings(int x, int y, void *param);
int					mouse_hook_settings(int b, int x, int y, void *param);

void				mandelbrot(t_menu *men);
void				init_mandelbrot(t_mandelbrot *m, void *mlx);
void				find_ratio_m(t_mandelbrot *m, int x, int y);
int					key_hook_mandelbrot(int key, void *param);
int					mouse_hook_mandelbrot(int button, int x, int y, void *param);

void				julia(t_menu *men);
void				init_julia(t_julia *j, void *mlx);
void				find_ratio_j(t_julia *j, int x, int y);
int					key_hook_julia(int key, void *param);
int					mouse_motion_hook_julia(int x, int y, void *param);
int					mouse_hook_julia(int button, int x, int y, void *param);

void				burningship(t_menu *men);
void				find_ratio_b(t_burningship *b, int x, int y);
void				init_burningship(t_burningship *b, void *mlx);
int					key_hook_burningship(int key, void *param);
int					mouse_hook_burningship(int button, int x, int y, void *param);

#endif
