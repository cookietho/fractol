/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 12:53:24 by minakim           #+#    #+#             */
/*   Updated: 2019/02/21 16:25:00 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	directions(void)
{
	ft_putendl("**************CONTROLS**************");
	ft_putendl("**           exit : ESC           **");
	ft_putendl("**          Reset : 'R'           **");
	ft_putendl("**  Zoom in : '+' Zoom out : '-'  **");
	ft_putendl("**    Arrow keys : movement       **");
	ft_putendl("**     Mouse scroll : Zoom        **");
	ft_putendl("**     Color : 1,2,3,4,5,6        **");
	ft_putendl("** Color range shift : 'T' & 'Y'  **");
	ft_putendl("**       Set : Q,W,E,A,S          **");
	ft_putendl("************************************");
}

void	init_set(t_fractol *m)
{
	m->mdb = (t_set*)malloc(sizeof(t_set));
	if (m->set == 1 || m->set == 5)
	{
		m->mdb->min_re = -2.15;
		m->mdb->max_re = 1.15;
		m->mdb->min_im = -1.15;
		m->mdb->max_im = m->mdb->min_im + (m->mdb->max_re - m->mdb->min_re)
			* m->win_h / m->win_w;
	}
	else if (m->set == 2 || m->set == 4)
	{
		m->mdb->min_re = -1.65;
		m->mdb->max_re = 1.65;
		m->mdb->min_im = -1.15;
		m->mdb->max_im = m->mdb->min_im + (m->mdb->max_re - m->mdb->min_re)
			* m->win_h / m->win_w;
	}
	else if (m->set == 3)
	{
		m->mdb->min_re = -2.16;
		m->mdb->max_re = 1.5;
		m->mdb->max_im = -1.87;
		m->mdb->min_im = m->mdb->max_im + (m->mdb->max_re - m->mdb->min_re)
			* m->win_h / m->win_w;
	}
}

void	reset(t_fractol *m)
{
	m->win_w = WIDTH;
	m->win_h = HEIGHT;
	m->x = 0;
	m->y = 0;
	m->z = 150;
	m->cursor = 0;
	m->max_color = 0x000000;
	m->color = 1;
	m->rg = 16;
	m->gb = 8;
	init_set(m);
}

void	init_mlx(t_fractol *m)
{
	m->win_w = WIDTH;
	m->win_h = HEIGHT;
	m->x = 0;
	m->y = 0;
	m->z = 150;
	m->max_color = 0x000000;
	m->color = 1;
	m->rg = 16;
	m->gb = 8;
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, m->win_w, m->win_h, "FRACTOL");
	m->img_ptr = mlx_new_image(m->mlx_ptr, m->win_w, m->win_h);
	m->mlx_data = mlx_get_data_addr(m->img_ptr, &m->bpp, &m->size_line,
			&m->endian);
	init_set(m);
}
