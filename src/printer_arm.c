/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_arm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:51:12 by alero             #+#    #+#             */
/*   Updated: 2021/02/18 17:44:27 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		printer_arm(t_image img, void (*funct)(t_image))
{
	while (img.y < img.reso_y)
	{
		while (img.x < img.reso_x)
		{
			funct(img);
			img.x++;
		}
		img.x = 0;
		img.y++;
	}
}
