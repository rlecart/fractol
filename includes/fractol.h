/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:04:41 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/09 05:45:29 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft.h>
# include <graphics.h>

typedef struct		s_julia
{
	int				i;
	int				x;
	int				y;
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

typedef struct		s_buddhabrot
{
	int				i;
	int				x;
	int				y;
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
}					t_buddhabrot;

typedef struct		s_pal
{
	t_color			col[5];
	struct s_pal	*before;
	struct s_pal	*next;
}					t_pal;

typedef struct		s_settings
{
	int				choice;
	t_pal			*pal;
	char			*img;
	void			*win;
	void			*data;
}					t_settings;

typedef struct		s_menu
{
	char			*img;
	void			*data;
	void			*mlx;
	void			*win;
	t_julia			j;
	t_mandelbrot	m;
	t_buddhabrot	b;
	t_settings		s;
}					t_menu;

void				menu(t_menu *men, int choice);
void				init(t_menu *men);
void				julia(t_menu *men);
void				mandelbrot(t_menu *men);
void				buddhabrot(t_menu *men);
void				find_ratio_m(t_mandelbrot *m, int x, int y);
void				find_ratio_j(t_julia *j, int x, int y);
void				find_ratio_b(t_buddhabrot *b, int x, int y);
int					key_hook_menu(int key, void *param);
int					mouse_motion_hook(int x, int y, void *param);
int					mouse_release_hook_menu(int b, int x, int y, void *param);
int					mouse_hook_menu(int button, int x, int y, void *param);
int					mouse_motion_hook_menu(int x, int y, void *param);
int					key_hook_menu(int key, void *param);
void				destroy_window(t_menu *men);
void				settings(t_menu *men);
int					key_hook_settings(int key, void *param);
int					mouse_motion_hook_settings(int x, int y, void *param);
int					mouse_hook_settings(int b, int x, int y, void *param);
void				roll_palette(t_pal **pal);

#endif
