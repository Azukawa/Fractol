/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:27:25 by alero             #+#    #+#             */
/*   Updated: 2021/03/08 11:24:47 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../minilibx-linux-master/mlx.h"
# include "../Libft/inc/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct	s_image
{
	char		*buffer;
	int			pixel;
	int			size_line;
	int			bit_per_pixel;
	int			endian;
	int			x;
	int			y;
	int			max_iter;
	int			color;
	int			reso_x;
	int			reso_y;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			code;
	int			m_x;
	int			m_y;
	double		r;
	double		zx;
	double		zy;
	double		cx;
	double		cy;
	double		xtemp;
}				t_image;

void			draw_pixel(t_image img);
void			julia_point(t_image img);
void			mndlslw_point(t_image img);
void			barsleyfern(t_image img);
void			printer_arm(t_image img, void (*funct)(t_image));
void			image_builder(t_image img);
t_image			*img_init(t_image *img);
int				check_arg(int argc, char *arg);
int				key_callback(int kcode, t_image *img);
int				mouse_callback(int kcode, int x, int y, t_image *img);
int				loop_callback(t_image *img);
int				mouse_move(int x, int y, t_image *img);

#endif
