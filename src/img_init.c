/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:53:43 by alero             #+#    #+#             */
/*   Updated: 2021/03/04 12:51:26 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

t_image	*img_init(t_image *img)
{
	img->max_iter = 15;
	img->reso_x = 800;
	img->reso_y = 500;
	img->x = 0;
	img->y = 0;
	img->color = 0xff00ff;
	img->r = 0.5;
	img->zx = 0;
	img->zy = 0;
	img->cx = 0;
	img->cy = 0;
	return (img);
}
