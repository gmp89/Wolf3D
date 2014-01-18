/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/14 18:27:22 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/18 19:01:43 by gpetrov          ###   ########.fr       */
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

void	draw_player(t_data *d)
{
	double	tmpx;
	double	tmpy;

	tmpx = d->p->x;
	tmpy = d->p->y;
	ft_put_pixel_to_img(d, d->p->x, d->p->y, WHITE);
	ft_put_pixel_to_img(d, d->p->x + 1, d->p->y, WHITE);
	ft_put_pixel_to_img(d, d->p->x, d->p->y + 1, WHITE);
	ft_put_pixel_to_img(d, d->p->x, d->p->y, WHITE);
	d->p->x = tmpx;
	d->p->y = tmpy;
}

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
		line2.b.y = ((line2.a.y) + (SIZE_WINY / d->li));

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

int		ft_collision(t_data *d, t_point *pos)
{
	if (*d->map[((int)pos->y) / SIZE_BLOCK][((int)pos->x) / SIZE_BLOCK] == d->wall)
		return (-1);
	return (0);
	 /*if (*d->map[pos->y / SIZE_BLOCK][pos->x / SIZE_BLOCK] == d->wall) 
	 {  
	 	if (d->pos->x == ((pos->x / SIZE_BLOCK) * SIZE_BLOCK)) 
	 		return (1); 
	 	else if (pos->x == (((pos->x / SIZE_BLOCK) + 1) * SIZE_BLOCK - 1)) 
	 		return (2); 
	 	else if (pos->y == ((pos->y / SIZE_BLOCK) * SIZE_BLOCK)) 
	 		return (3); 
	 	else if (pos->y == (((pos->y / SIZE_BLOCK) + 1) * SIZE_BLOCK - 1)) 
	 		return (4); 
	 	else 
	 		return (5); 
	 } 
	 return (0); */
}

void	ft_clean(t_data *d)
{
	int		i;
	int		j;
	i = 0;
	j = 0;
	while (i <= SIZE_WINY)
	{
		while (j <= SIZE_WINX)
		{
			ft_put_pixel_to_img(d, j, i, 0x000000);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_print_wolf(t_data *d, int dist, double dist_screen, int i)
{
	double	height;
	t_point	a;
	t_point	b;
	int		ya;
	int		yb;

	/*printf("eb_print_wolf:dist %f\n", col->dist);*/
	height = ((dist_screen * (double)SIZE_BLOCK) / dist);
	/*printf("height : %d\n", height);*/
	ya = ((SIZE_WINY / 2) - (int)(height / 2));
	ya = (ya <= 0 ? 1 : ya);
	yb = ((SIZE_WINY / 2) + (int)(height / 2));
	yb = (yb >= SIZE_WINY ? SIZE_WINY : yb);
	/*printf("color = %f \t", (dist / MAXLEN));*/
	/* eb_init_pos(i, ya, &a); */
	a.x = i;
	a.y = ya;
	/* eb_init_pos(i, yb, &b); */
	b.x = i;
	b.y = yb;
	/*eb_trace_line(d, a, b, 0xFFFFFF * ((dist * 2) / MAXLEN));*/
	ft_trace_line(d, &a, &b, ORANGE);
	/*if (col->face == 1)
	{
		ft_trace_line(d, &a, &b, 0xFF0000);
	}
	else if (col->face == 2)
	{
		ft_trace_line(d, &a, &b, 0x00FF00);
	}
	else if (col->face == 3)
	{
		ft_trace_line(d, &a, &b, 0x0000FF);
	}
	else if (col->face == 4)
	{
		ft_trace_line(d, &a, &b, 0xFF7F00);
	}
	else
	{
		ft_trace_line(d, &a, &b, 0xFFFFFF);
	}*/
}

void	ft_raycast(t_data *d)
{
	double		alpha;
	int			i;
	double		dist_screen;
	double		x;
	double		y;
	int			dist;

	d->hit = (t_hit *)malloc(sizeof(t_hit));
	d->pos_tmp = (t_point *)malloc(sizeof(t_point));

	dist_screen = ((SIZE_WINX / 2) / tan((60 * RAD) / 2));
	i = -(SIZE_WINX / 2) - 1;
	while (++i <= (SIZE_WINX / 2))
	{
		alpha = d->alpha + atan(i / dist_screen);
		dist = 0;
		d->pos_tmp->x = d->p->x;
		d->pos_tmp->y = d->p->y;
		x = d->pos_tmp->x;
		y = d->pos_tmp->y;
		while (ft_collision(d, d->pos_tmp) == 0)
		{
			/*usleep(10000);*/
			/*ft_put_pixel_to_img(d, (x), (y), YELLOW);*/
			/* usleep(1000000); */
			d->pos_tmp->x = x;
			d->pos_tmp->y = y;
			x = x + (cos(alpha) * 1);
			y = y + (sin(alpha) * 1);
			dist += 1;
			/*printf("(%d:%d) dist = %d\n", d->pos_tmp->x, d->pos_tmp->y, dist);*/
		}
		dist = dist * cos(alpha - d->alpha);
		ft_print_wolf(d, dist, dist_screen, i + (SIZE_WINX / 2));

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
	ft_clean(d);
	ft_draw_background(d); 
	/* ft_raycast(d); */
	/*draw_map(d);
	draw_player(d);*/
	ft_raycast(d);
}
