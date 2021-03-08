/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_callback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:59:02 by alero             #+#    #+#             */
/*   Updated: 2021/03/08 11:28:40 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int			mouse_move(int x, int y, t_image *img)
{
	img->m_x = x;
	img->m_y = y;
	return (1);
}

int			mouse_callback(int kcode, int x, int y, t_image *img)
{
	y = x;
	x = y;
	if (kcode == 5)
		img->r = img->r * 1.05;
	else if (kcode == 4)
		img->r = img->r * 0.95;
	return (1);
}
