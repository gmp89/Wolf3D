/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 18:27:22 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/14 22:10:57 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_draw_background(t_data *d)
{
	d->wi->x = 0;
	d->wi->y = 0;
	while (d->wi->y <= SIZE_WINY / 2)
	{
		while (d->wi->x < SIZE_WINX)
		{
			ft_put_pixel_to_img(d, d->wi->x, d->wi->y, BLUE);
			d->wi->x++;
		}
		d->wi->x = 0;
		d->wi->y++;
	}
	d->wi->y = (SIZE_WINY / 2);
	while (d->wi->y <= SIZE_WINY)
	{
		while (d->wi->x < SIZE_WINX)
		{
			ft_put_pixel_to_img(d, d->wi->x, d->wi->y, GREY);
			d->wi->x++;
		}
		d->wi->x = 0;
		d->wi->y++;
	}
}

void	ft_raycast(t_data *d)
{
	int		x;
	int		x_max;

	x = 0;
	x_max = SIZE_WINX;
	while (x < SIZE_WINX)
	{
		///calcul de la position et de l'orientation du rayon
		d->wi->cam_x = 2 * x / (double)x_max - 1; ///Coordonner x dans l'espace de la camera
		d->wi->ray_pos_x = d->wi->pos_x; ///  Coordonner x de rayon dans l'espace
		d->wi->ray_pos_y = d->wi->pos_y;                 /// Coordonner y de rayon dans l'espace
		d->wi->ray_dir_x = d->wi->dir_x + d->wi->plane_x * d->wi->cam_x;
		d->wi->ray_dir_y = d->wi->dir_y + d->wi->plane_y * d->wi->cam_x;
		d->wi->map_x = (int)d->wi->ray_pos_x;
		d->wi->map_y = (int)d->wi->ray_pos_y;
		d->wi->dist2_wall_x = sqrt(1 + (d->wi->ray_dir_y * d->wi->ray_dir_y) / (d->wi->ray_dir_x * d->wi->ray_dir_x)); ///Distance entre deux murs verticaux
		d->wi->dist2_wall_y = sqrt(1 + (d->wi->ray_dir_x * d->wi->ray_dir_x) / (d->wi->ray_dir_y * d->wi->ray_dir_y)); ///Distance entre deux murs horizontaux
		x++;
	}
}

void	ft_draw(t_data *d)
{
	ft_draw_background(d);
	/* d->wi->x = 0; */
	/* d->wi->y = 0; */
	/* while (d->wi->y <= 100) */
	/* { */
	/* 	while (d->wi->x < 100) */
	/* 	{ */
	/* 		ft_put_pixel_to_img(d, d->wi->x, d->wi->y, GREEN); */
	/* 		d->wi->x++; */
	/* 	} */
	/* 	d->wi->x = 0; */
	/* 	ft_put_pixel_to_img(d, d->wi->x, d->wi->y, GREEN); */
	/* 	d->wi->y++; */
	/* } */
	ft_raycast(d);
}
