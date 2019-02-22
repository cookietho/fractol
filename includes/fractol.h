/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 12:22:01 by minakim           #+#    #+#             */
/*   Updated: 2019/02/21 17:28:58 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <pthread.h>
# define BUF_SIZE 99999
# define WIDTH 1200
# define HEIGHT 900

typedef struct		s_fractol
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*mlx_data;
	int				win_w;
	int				win_h;
	intmax_t		x;
	intmax_t		y;
	intmax_t		z;
	int				cursor;
	int				color;
	int				rg;
	int				gb;
	unsigned int	max_color;
	int				bpp;
	int				size_line;
	int				endian;
	int				set;
	int				iter;
	int				start;
	int				end;
	float			zoom;
	struct s_set	*mdb;
}					t_fractol;

typedef struct		s_set
{
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			k_r;
	double			k_i;
}					t_set;

int					main(int ac, char **av);
void				screen_msg(t_fractol *m);
void				directions(void);
void				fractal_type(t_fractol *m, char *av);
void				error_handling(int n);
void				map(t_fractol *m);

void				init_set(t_fractol *m);
void				reset(t_fractol *m);
void				init_mlx(t_fractol *m);

void				render(t_fractol *m);
void				multithread(t_fractol *arg, t_fractol *m);

unsigned int		get_color(int i, t_fractol *m);
void				colorit(int key, t_fractol *m);

void				put_pixel(t_fractol *m, int x, int y, unsigned int c);
void				zoom(int key, t_fractol *m);
void				keyfunction(int key, t_fractol *m);
void				change_set(int key, t_fractol *m);
int					handlekey(int key, t_fractol *m);

void				mouse_zoom(int button, int x, int y, t_fractol *m);
int					mouseoperation(int button, int x, int y, t_fractol *m);
int					cursoroperation(int x, int y, t_fractol *m);

void				*mandelbrot(void *arg);
void				iterate_mandelbrot(t_fractol *m, float c_re, float c_im);

void				iterate_julia(t_fractol *m, float c_re, float c_im);
void				*julia(void *arg);

void				iterate_burning(t_fractol *m, float c_re, float c_im);
void				*burning(void *arg);

void				iterate_tricorn(t_fractol *m, float c_re, float c_im);
void				*tricorn(void *arg);

void				iterate_special(t_fractol *m, float c_re, float c_im);
void				*special(void *arg);
#endif
