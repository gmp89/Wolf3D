/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 14:40:10 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/18 18:36:59 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

void	ft_init_attr(t_data *d)
{
	d->wi->grid_x = (SIZE_WINX / 64);
	d->wi->grid_y = (SIZE_WINY / 64);
}

int		main(int argc, char **argv)
{
	int		***tab;
	t_conf	conf;
	t_data	d;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf [data_file]");
		return (0);
	}
	tab = ft_get_data(argv, &conf);
	d.map = tab;
	d.wall = conf.wall;
	d.col = conf.x;
	d.li = conf.y;
	d.empty = conf.empty;
	d.p = (t_point *)malloc(sizeof(t_point));
	d.p->x = 1040;
	d.p->y = 1104;
	d.alpha = 0;
	ft_init_attr(&d);
	ft_print_map(d.map);
	ft_mlx(&d);
	return (0);
}
