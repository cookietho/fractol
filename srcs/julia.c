/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 15:43:17 by minakim           #+#    #+#             */
/*   Updated: 2019/02/20 10:20:37 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SETS t_fractol *m = (t_fractol *)arg;
#include "../includes/fractol.h"

void	iterate_julia(t_fractol *m, float c_re, float c_im)
{
	intmax_t	i;
	double		z_re;
	double		z_im;
	double		z_re2;
	double		z_im2;

	m->iter = 50;
	z_re = c_re;
	z_im = c_im;
	i = 0;
	while (i < m->iter)
	{
		z_re2 = z_re * z_re;
		z_im2 = z_im * z_im;
		if ((z_re2 + z_im2) > 4)
			break ;
		z_im = (2 * z_re * z_im) + m->mdb->k_i;
		z_re = z_re2 - z_im2 + m->mdb->k_r;
		i++;
	}
	put_pixel(m, m->x, m->y, get_color(i, m));
}

void	*julia(void *arg)
{
	float		c_re;
	float		c_im;

	SETS;
	m->y = m->start - 1;
	while (++(m->y) < m->end)
	{
		m->x = -1;
		while (++(m->x) < m->win_w)
		{
			c_im = m->mdb->max_im - ((double)m->y * ((m->mdb->max_im -
							m->mdb->min_im) / (m->win_h - 1)));
			c_re = m->mdb->min_re + ((double)m->x * ((m->mdb->max_re -
							m->mdb->min_re) / (m->win_w - 1)));
			iterate_julia(m, c_re, c_im);
		}
	}
	return (NULL);
}
