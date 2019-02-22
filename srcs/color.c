/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:56:04 by minakim           #+#    #+#             */
/*   Updated: 2019/02/20 10:13:14 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <stdio.h>

unsigned int	get_color(int i, t_fractol *m)
{
	unsigned int	c;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (i == 0 || i == m->iter)
		return (m->color);
	r = (i * 5) * m->color;
	g = (255 - (i * 10)) * m->color;
	b = (255 - (i * 2)) * m->color;
	c = (r << m->rg) + (g << m->gb) + b;
	return (c);
}

void			colorit2(int key, t_fractol *m)
{
	if (key == 21)
	{
		m->color = -1;
		m->rg = 16;
		m->gb = 16;
	}
	else if (key == 23)
	{
		m->color = 1;
		m->rg = 8;
		m->gb = 8;
	}
	else if (key == 22)
	{
		m->color = -1;
		m->rg = 8;
		m->gb = 8;
	}
	else if (key == 17)
		m->color += 1;
	else
		m->color -= 1;
}

void			colorit(int key, t_fractol *m)
{
	if (key == 18)
	{
		m->rg = 16;
		m->gb = 8;
		m->color = 1;
	}
	else if (key == 19)
	{
		m->rg = 16;
		m->gb = 8;
		m->color = -1;
	}
	else if (key == 20)
	{
		m->rg = 16;
		m->gb = 16;
		m->color = 1;
	}
	else
		colorit2(key, m);
}
