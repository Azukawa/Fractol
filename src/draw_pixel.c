/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:42:45 by alero             #+#    #+#             */
/*   Updated: 2021/03/08 11:27:02 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
**	img.color = BLUE;
**	img.color >> 8 = GREEN;
**	img.color >> 16 = RED;
*/

void		draw_pixel(t_image img)
{
	img.pixel = (img.y * img.size_line) + (img.x * 4);
	if (img.pixel >= 0 && img.pixel < img.reso_x * img.reso_y * 4)
	{
		img.buffer[img.pixel] = img.color;
		img.buffer[img.pixel + 1] = (img.color >> 8);
		img.buffer[img.pixel + 2] = (img.color >> 16);
	}
}
