/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 20:20:23 by minakim           #+#    #+#             */
/*   Updated: 2019/02/20 10:32:36 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

void	mouse_zoom(int button, int x, int y, t_fractol *m)
{
	double	r_zoom;
	double	i_zoom;
	int		i;

	if (button == 1)
	{
	}
	else if (button == 4 || button == 5)
	{
		i = (button == 5) ? -1 : 1;
		if (i == 1)
		{
			i_zoom = (m->mdb->max_im - m->mdb->min_im) * 0.1;
			r_zoom = (m->mdb->max_re - m->mdb->min_re) * 0.1;
		}
		else
		{
			i_zoom = (m->mdb->max_im - m->mdb->min_im) / (9);
			r_zoom = (m->mdb->max_re - m->mdb->min_re) / (9);
		}
		m->mdb->max_re += (i * r_zoom) * ((m->win_w - (double)x) / m->win_w);
		m->mdb->min_re -= (i * r_zoom) * ((double)x / m->win_w);
		m->mdb->max_im += (i * i_zoom) * ((double)y / m->win_h);
		m->mdb->min_im -= (i * i_zoom) * ((m->win_h - (double)y) / m->win_h);
	}
}

int		mouseoperation(int button, int x, int y, t_fractol *m)
{
	(button == 1 || button == 4 || button == 5) ?
		mouse_zoom(button, x, y, m) : 0;
	render(m);
	screen_msg(m);
	return (0);
}

int		cursoroperation(int x, int y, t_fractol *m)
{
	if (x < 0 || x >= m->win_w || y < 0 || y >= m->win_h || m->set == 1
			|| m->set == 3)
		return (0);
	m->mdb->k_r = m->mdb->min_re + (double)x * (m->mdb->max_re -
			m->mdb->min_re) / (m->win_w - 1);
	m->mdb->k_i = m->mdb->min_im + (double)y * (m->mdb->max_im -
			m->mdb->min_im) / (m->win_h - 1);
	render(m);
	screen_msg(m);
	return (0);
}
