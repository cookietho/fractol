/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:28:28 by minakim           #+#    #+#             */
/*   Updated: 2019/02/20 10:28:59 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_pixel(t_fractol *m, int x, int y, unsigned int c)
{
	int	i;

	i = (x * 4) + (y * m->size_line);
	m->mlx_data[i] = c;
	m->mlx_data[++i] = c >> 8;
	m->mlx_data[++i] = c >> 16;
}

void	zoom(int key, t_fractol *m)
{
	double	r_zoom;
	double	i_zoom;

	if (key == 24)
	{
		i_zoom = (m->mdb->max_im - m->mdb->min_im) * 0.05;
		r_zoom = (m->mdb->max_re - m->mdb->min_re) * 0.05;
		m->mdb->max_re += (-1 * r_zoom);
		m->mdb->min_re -= (-1 * r_zoom);
		m->mdb->max_im += (-1 * i_zoom);
		m->mdb->min_im -= (-1 * i_zoom);
	}
	else
	{
		i_zoom = (m->mdb->max_im - m->mdb->min_im) / (2 * 9);
		r_zoom = (m->mdb->max_re - m->mdb->min_re) / (2 * 9);
		m->mdb->max_re += (1 * r_zoom);
		m->mdb->min_re -= (1 * r_zoom);
		m->mdb->max_im += (1 * i_zoom);
		m->mdb->min_im -= (1 * i_zoom);
	}
}

void	keyfunction(int key, t_fractol *m)
{
	if (key == 123)
	{
		m->mdb->max_re += (m->mdb->max_re - m->mdb->min_re) * 0.05;
		m->mdb->min_re += (m->mdb->max_re - m->mdb->min_re) * 0.05;
	}
	else if (key == 124)
	{
		m->mdb->max_re -= (m->mdb->max_re - m->mdb->min_re) * 0.05;
		m->mdb->min_re -= (m->mdb->max_re - m->mdb->min_re) * 0.05;
	}
	else if (key == 125)
	{
		m->mdb->max_im += (m->mdb->max_im - m->mdb->min_im) * 0.05;
		m->mdb->min_im += (m->mdb->max_im - m->mdb->min_im) * 0.05;
	}
	else
	{
		m->mdb->max_im -= (m->mdb->max_im - m->mdb->min_im) * 0.05;
		m->mdb->min_im -= (m->mdb->max_im - m->mdb->min_im) * 0.05;
	}
}

void	change_set(int key, t_fractol *m)
{
	if (key == 12)
	{
		m->set = 1;
		init_set(m);
	}
	else if (key == 13)
	{
		m->set = 2;
		init_set(m);
	}
	else if (key == 14)
	{
		m->set = 3;
		init_set(m);
	}
	else if (key == 0)
	{
		m->set = 4;
		init_set(m);
	}
	else if (key == 1)
	{
		m->set = 5;
		init_set(m);
	}
}

int		handlekey(int key, t_fractol *m)
{
	key == 53 ? exit(0) : 0;
	key == 15 ? reset(m) : 0;
	(key >= 123 && key <= 126) ? keyfunction(key, m) : 0;
	(key == 27 || key == 24) ? zoom(key, m) : 0;
	(key >= 16 && key <= 23) ? colorit(key, m) : 0;
	((key >= 12 && key <= 14) || (key >= 0 && key <= 1)) ?
		change_set(key, m) : 0;
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	render(m);
	screen_msg(m);
	return (0);
}
