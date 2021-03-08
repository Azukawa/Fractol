/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 13:55:27 by alero             #+#    #+#             */
/*   Updated: 2021/03/08 11:13:30 by alero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		check_arg(int argc, char *arg)
{
	if (argc != 2)
	{
		ft_putstr("Wrong number of arguments.\nPlease \
enter one of the following:\n'Mandel', 'Julia' or 'Barnsley'\n");
		exit(1);
	}
	if (ft_strcmp(arg, "Barnsley") == 0)
		return (3);
	else if (ft_strcmp(arg, "Mandel") == 0)
		return (1);
	else if (ft_strcmp(arg, "Julia") == 0)
		return (2);
	else
	{
		ft_putstr("Incorrect argument.\nPlease enter \
one of the following:\n'Mandel', 'Julia' or 'Barnsley'\n");
		exit(0);
	}
}
