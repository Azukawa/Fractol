/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barsleyfern.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:49:43 by alero             #+#    #+#             */
/*   Updated: 2021/03/08 11:25:13 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_image		barsley_pt2(int dice, t_image img)
{
	if (dice == 0)
	{
		img.cx = 0 * img.xtemp;
		img.cy = (0.16 * img.zy) * img.xtemp;
	}
	else if (dice >= 1 && dice <= 7)
	{
		img.cx = (-0.15 * img.zx + 0.28 * img.zy) * img.xtemp;
		img.cy = (0.26 * img.zx + 0.24 * img.zy + 0.44) * img.xtemp;
	}
	else if (dice >= 8 && dice <= 15)
	{
		img.cx = (0.2 * img.zx - 0.26 * img.zy) * img.xtemp;
		img.cy = (0.23 * img.zx + 0.85 * 1.6) * img.xtemp;
	}
	else
	{
		img.cx = (0.85 * img.zx + 0.04 * img.zy) * img.xtemp;
		img.cy = (-0.04 * img.zx + 0.85 * img.zy + 1.6) * img.xtemp;
	}
	return (img);
}

/*
**	xtemp = multiplyer.
*/

void		barsleyfern(t_image img)
{
	int				dice;
	unsigned long	seed;
	int				iter;
	int				mys;

	seed = 11;
	mys = 30 + img.r;
	img.xtemp = 1.01;
	iter = 120000;
	img.color = 0x0000FF;
	while (iter > 0)
	{
		dice = ft_myrand(&seed) % 100;
		img = barsley_pt2(dice, img);
		img.x = (img.m_x - mys * 0.01) + mys * img.cx + img.reso_x / 2 + 400;
		img.y = (img.m_y - (mys * img.m_y) * 0.01) + mys * img.cy;
		draw_pixel(img);
		img.zx = img.cx;
		img.zy = img.cy;
		iter--;
		img.color++;
	}
}
