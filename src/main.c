/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlecart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 03:04:09 by rlecart           #+#    #+#             */
/*   Updated: 2017/06/28 22:13:42 by rlecart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		verif(char *f)
{
	ft_lowercase(&f);
	if ((ft_strcmp(f, "mandelbrot")) == 0)
		return (1);
	if ((ft_strcmp(f, "julia")) == 0)
		return (2);
	if ((ft_strcmp(f, "burningship")) == 0)
		return (3);
	if ((ft_strcmp(f, "menu")) == 0)
		return (4);
	if ((ft_strcmp(f, "settings")) == 0)
		return (5);
	return (-1);
}

int		main(int argc, char **argv)
{
	int		choice;
	t_menu	men;

	if (argc != 2 || (choice = verif(argv[1])) == -1)
	{
		ft_putstr("usage ./fractol param\n");
		ft_putstr("- Mandelbrot\n");
		ft_putstr("- Julia\n");
		ft_putstr("- Burningship\n");
		ft_putstr("- Menu\n");
		ft_putstr("- Settings\n");
		return (-1);
	}
	init(&men);
	menu(&men, choice);
	mlx_loop(men.mlx);
	return (0);
}
