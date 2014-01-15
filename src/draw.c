/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 18:27:22 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/15 22:31:55 by gpetrov          ###   ########.fr       */
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

/* void	ft_raycast(t_data *d) */
/* { */
/* 	int		x; */
/* 	int		x_max; */

/* 	x = 0; */
/* 	x_max = SIZE_WINX; */
/* 	while (x < SIZE_WINX) */
/* 	{ */
/* 		///calcul de la position et de l'orientation du rayon */
/* 		d->wi->cam_x = 2 * x / (double)x_max - 1; ///Coordonner x dans l'espace de la camera */
/* 		d->wi->ray_pos_x = d->wi->pos_x; ///  Coordonner x de rayon dans l'espace */
/* 		d->wi->ray_pos_y = d->wi->pos_y;                 /// Coordonner y de rayon dans l'espace */
/* 		d->wi->ray_dir_x = d->wi->dir_x + d->wi->plane_x * d->wi->cam_x; */
/* 		d->wi->ray_dir_y = d->wi->dir_y + d->wi->plane_y * d->wi->cam_x; */
/* 		d->wi->map_x = (int)d->wi->ray_pos_x; */
/* 		d->wi->map_y = (int)d->wi->ray_pos_y; */
/* 		d->wi->dist2_wall_x = sqrt(1 + (d->wi->ray_dir_y * d->wi->ray_dir_y) / (d->wi->ray_dir_x * d->wi->ray_dir_x)); ///Distance entre deux murs verticaux */
/* 		d->wi->dist2_wall_y = sqrt(1 + (d->wi->ray_dir_x * d->wi->ray_dir_x) / (d->wi->ray_dir_y * d->wi->ray_dir_y)); ///Distance entre deux murs horizontaux */
/* 		x++; */
/* 	} */
/* } */

/* void	block(t_data *d, int x, int y) */
/* { */
/* 	int		i; */
/* 	int		j; */

/* 	i = 0; */
/* 	j = 0; */
/* 	while (j) */
/* } */

void	draw_map(t_data *d)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (d->map[i])
	{
		while (d->map[i][j])
		{
			ft_trace_block(d, j, i);
			j++;
		}
		j = 0;
		i++;
	}
	/* ft_trace_block(d, 1, 0); */
}



void	ft_trace_line(t_data *d, t_point *a, t_point *b, int color)
{
	int		x;
	int		y;

	if (a->x == b->x && a->y == b->y)
		return ;
	else if (abs(b->x - a->x) >= abs(b->y - a->y))
	{
		if (a->x > b->x)
			ft_swap_pos(a, b);
		x = a->x;
		while (x <= b->x)
		{
			y = a->y + ((b->y - a->y) * (x - a->x)) / (b->x - a->x);
			ft_put_pixel_to_img(d, x, y, color);
			x++;
		}
	}
	else
	{
		if (a->y > b->y)
			ft_swap_pos(a, b);
		y = a->y;
		while (y <= b->y)
		{
			x = a->x + ((b->x - a->x) * (y - a->y)) / (b->y - a->y);
			ft_put_pixel_to_img(d, x, y, color);
			y++;
		}
	}
}

/* t_line	*ft_init_line(int xa, int ya, int xb, int yb) */
/* { */
/* 	t_line	*line; */
/* 	t_pos	*a; */
/* 	t_pos	*b; */

/* 	line = (t_line *)malloc(sizeof(t_line)); */
/* 	a = (t_pos *)malloc(sizeof(t_pos)); */
/* 	b = (t_pos *)malloc(sizeof(t_pos)); */
/* 	a->x = xa; */
/* 	a->y = ya; */
/* 	b->x = xb; */
/* 	b->y = yb; */
/* 	line->a = a; */
/* 	line->b = b; */
/* 	return (line); */
/* } */

/* t_line	*line_init(int x1, int y1, int x2, int y2) */
/* { */
/* 	return (line) */
/* } */

void	ft_trace_block(t_data *d, int x, int y)
{
	t_line	line1;
	t_line	line2;
	t_line	line3;
	t_line	line4;

	if (*d->map[y][x] == d->wall)
	{
		line1.a.x = (x * (SIZE_WINX / d->col));
		line1.a.y = (y * (SIZE_WINY / d->li));
		line1.b.x = (((x + 1) * (SIZE_WINX / d->col)));
		line1.b.y = line1.a.y;

		line2.a.x = line1.b.x;
		line2.a.y = line1.b.y;
		line2.b.x = line2.a.x;
		line2.b.y = ((line2.a.y + 1) * (SIZE_WINY / d->li));

		line3.a.x = line2.b.x;
		line3.a.y = line2.b.y;
		line3.b.x = line1.a.x;
		line3.b.y = line3.a.y;

		line4.a.x = line3.b.x;
		line4.a.y = line3.b.y;
		line4.b.x = line1.a.x;
		line4.b.y = line1.a.y;

		ft_trace_line(d, &line1.a, &line1.b, GREEN);
		ft_trace_line(d, &line2.a, &line2.b, GREEN);
		ft_trace_line(d, &line3.a, &line3.b, GREEN);
		ft_trace_line(d, &line4.a, &line4.b, GREEN);
	}
}

void	ft_draw(t_data *d)
{
	t_point	a;
	t_point	b;

	a.x = 0;
	a.y = 0;
	b.x = 100;
	b.y = a.y;
	/* ft_draw_background(d); */
	draw_map(d);
	/* ft_trace_line(d, &a, &b, GREEN); */
}
