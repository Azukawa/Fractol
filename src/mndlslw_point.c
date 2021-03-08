/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mndlslw_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:47:19 by alero             #+#    #+#             */
/*   Updated: 2021/03/08 11:22:47 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		mndlslw_point(t_image img)
{
	int	iter;
	int	max_iter;
	int	i;

	max_iter = img.max_iter;
	i = 16777215 / max_iter;
	img.cx = (img.m_x - (img.r * img.m_x)) * (4.0 / 800) +\
img.r * img.x * (4.0 / 800) - 2.5;
	img.cy = (img.m_y - (img.r * img.m_y)) * (3.0 / 600) +\
img.r * img.y * (3.0 / 600) - 1.25;
	img.zx = 0;
	img.zy = 0;
	iter = 0;
	while (img.zx * img.zx + img.zy * img.zy <= 2 * 2 && iter < max_iter)
	{
		img.xtemp = img.zx * img.zx - img.zy * img.zy + img.cx;
		img.zy = 2 * img.zx * img.zy + img.cy;
		img.zx = img.xtemp;
		iter++;
	}
	if (iter >= max_iter)
		img.color = i;
	else
		img.color = i * iter;
	draw_pixel(img);
}
