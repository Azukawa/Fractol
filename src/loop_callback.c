/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_callback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:00:29 by alero             #+#    #+#             */
/*   Updated: 2021/03/08 11:14:25 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int			loop_callback(t_image *img)
{
	image_builder(*img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr,\
	img->img_ptr, img->x, img->y);
	return (0);
}
