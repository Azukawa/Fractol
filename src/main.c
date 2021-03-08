/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:01:28 by alero             #+#    #+#             */
/*   Updated: 2021/03/08 11:28:59 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int			main(int argc, char **argv)
{
	t_image	*img;

	img = (t_image *)ft_memalloc(sizeof(t_image));
	img->code = check_arg(argc, argv[1]);
	img = img_init(img);
	img->mlx_ptr = mlx_init();
	img->win_ptr = mlx_new_window(img->mlx_ptr, img->reso_x, \
img->reso_y, "Drift deeper");
	img->img_ptr = mlx_new_image(img->mlx_ptr, img->reso_x, img->reso_y);
	img->buffer = mlx_get_data_addr(img->img_ptr, &img->bit_per_pixel, \
&img->size_line, &img->endian);
	mlx_mouse_hook(img->win_ptr, mouse_callback, img);
	mlx_hook(img->win_ptr, 6, 1L << 6, mouse_move, img);
	mlx_key_hook(img->win_ptr, key_callback, img);
	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, \
img->img_ptr, img->x, img->y);
	mlx_loop_hook(img->mlx_ptr, loop_callback, img);
	mlx_loop(img->mlx_ptr);
}
