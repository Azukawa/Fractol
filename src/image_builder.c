/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_builder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:52:06 by alero             #+#    #+#             */
/*   Updated: 2021/03/08 11:15:50 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		image_builder(t_image img)
{
	if (img.code == 1)
		printer_arm(img, mndlslw_point);
	else if (img.code == 2)
		printer_arm(img, julia_point);
	else if (img.code == 3)
	{
		ft_memset(img.buffer, 0, img.reso_x * img.reso_y * 4);
		barsleyfern(img);
	}
}
