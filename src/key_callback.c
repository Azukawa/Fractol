/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_callback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:57:11 by alero             #+#    #+#             */
/*   Updated: 2021/03/08 11:26:21 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		key_callback(int kcode, t_image *img)
{
	if (kcode == 53 || kcode == 65307)
	{
		mlx_destroy_window(img->mlx_ptr, img->win_ptr);
		exit(1);
	}
	else if (kcode == 65453)
		img->max_iter--;
	else if (kcode == 65451)
		img->max_iter++;
	return (0);
}
