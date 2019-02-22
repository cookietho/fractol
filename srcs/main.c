/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 12:50:48 by minakim           #+#    #+#             */
/*   Updated: 2019/02/21 17:37:24 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	error_handling(int n)
{
	if (n == 1)
	{
		ft_putstr("./fractol <SET>\n");
		ft_putstr("SET :\tMandelbrot\n\tJulia\n\tBurningship\n\tTricorn");
		exit(0);
	}
	else if (n == 2)
	{
		ft_putstr("INVALID SET\n");
		ft_putstr("SET :\tMandelbrot\n\tJulia\n\tBurningship\n\tTricorn");
		exit(0);
	}
}

void	fractal_type(t_fractol *m, char *av)
{
	if (ft_strcmp(av, "Mandelbrot") == 0)
		m->set = 1;
	else if (ft_strcmp(av, "Julia") == 0)
		m->set = 2;
	else if (ft_strcmp(av, "Burningship") == 0)
		m->set = 3;
	else if (ft_strcmp(av, "Tricorn") == 0)
		m->set = 4;
	else if (ft_strcmp(av, "Special") == 0)
		m->set = 5;
	else
		error_handling(2);
}

void	screen_msg(t_fractol *m)
{
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 5, 0xffffff, "[ESC] : EXIT");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 25, 0xffffff, "Reset : 'R'");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 45, 0xffffff, "Arrows : MOVE");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 65, 0xffffff, "Zoom : '+' '-'");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 85, 0xffffff, "Color : 1 - 6");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 105, 0xffffff, "ColorRange: T&Y");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 125, 0xffffff, "Mouse : Zoom");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 145, 0xffffff, "Set : Q,W,E,A,S");
}

void	map(t_fractol *h)
{
	init_mlx(h);
	render(h);
	screen_msg(h);
	mlx_hook(h->win_ptr, 2, 0, handlekey, h);
	mlx_hook(h->win_ptr, 6, 0, cursoroperation, h);
	mlx_mouse_hook(h->win_ptr, mouseoperation, h);
	mlx_loop(h->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_fractol	m;
	t_fractol	e;

	ft_bzero(&m, sizeof(t_fractol));
	if (ac == 2)
		fractal_type(&m, av[1]);
	else if (ac == 3)
	{
		if (!fork())
			fractal_type(&m, av[1]);
		else
		{
			ft_bzero(&e, sizeof(t_fractol));
			fractal_type(&e, av[2]);
			map(&e);
		}
	}
	else
		error_handling(1);
	directions();
	map(&m);
	return (0);
}
