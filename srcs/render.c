/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/20 13:48:35 by minakim           #+#    #+#             */
/*   Updated: 2019/02/20 10:00:49 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	multithread(t_fractol *arg, t_fractol *m)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		ft_memcpy((void*)&arg[i], m, sizeof(t_fractol));
		arg[i].start = i * (m->win_h / 4);
		arg[i].end = (i + 1) * (m->win_h / 4);
	}
}

void	render(t_fractol *m)
{
	int			i;
	pthread_t	t[4];
	t_fractol	arg[4];

	multithread(arg, m);
	i = -1;
	while (++i < 4)
	{
		m->set == 1 ? pthread_create(&t[i], NULL, mandelbrot, &arg[i]) : 0;
		m->set == 2 ? pthread_create(&t[i], NULL, julia, &arg[i]) : 0;
		m->set == 3 ? pthread_create(&t[i], NULL, burning, &arg[i]) : 0;
		m->set == 4 ? pthread_create(&t[i], NULL, tricorn, &arg[i]) : 0;
		m->set == 5 ? pthread_create(&t[i], NULL, special, &arg[i]) : 0;
	}
	i = -1;
	while (++i < 4)
		pthread_join(t[i], NULL);
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 0, 0);
}
