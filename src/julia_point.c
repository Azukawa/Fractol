/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:45:28 by alero             #+#    #+#             */
/*   Updated: 2021/02/18 21:02:57 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		julia_point(t_image img)
{
	int iter;
	int max_iter;
	int i;

	img.cx = ft_lerp_1d(0, 1, ft_clamp(0, img.reso_x, img.m_x) * 0.00125);
	img.cy = ft_lerp_1d(0, 1, ft_clamp(0, img.reso_y, img.m_y) * 0.002);
	iter = 0;
	max_iter = img.max_iter;
	i = 16777215 / max_iter;
	img.zx = ft_lerp_1d(img.r * -1 * 0.1, img.r * 0.1, 0.00125 * img.x);
	img.zy = ft_lerp_1d(img.r * -1 * 0.1, img.r * 0.1, 0.002 * img.y);
	while (img.zx * img.zx + img.zy * img.zy < (img.r * img.r)\
	&& iter < max_iter)
	{
		img.xtemp = img.zx * img.zx - img.zy * img.zy;
		img.zy = 2 * img.zx * img.zy + img.cy;
		img.zx = img.xtemp + img.cx;
		iter++;
	}
	if (iter >= max_iter)
		img.color = i;
	else
		img.color = i * iter;
	draw_pixel(img);
}
