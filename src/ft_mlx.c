/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 22:42:07 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/18 19:03:46 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_put_pixel_to_img(t_data *d, int x, int y, int color)
{
	unsigned int	new_color;
	int	i;

	new_color = mlx_get_color_value(d->mlx, color);
	i = x * 4 + y * d->sizeline;
	d->data[i] = (new_color & 0xFF);
	d->data[i + 1] = (new_color & 0xFF00) >> 8;
	d->data[i + 2] = (new_color & 0xFF0000) >> 16;
}

int		expose_hook(t_data *d)
{
	ft_draw(d);
	mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_data *d)
{
	d->i = 0;
	ft_putstr("button : ");
	ft_putnbr(button);
	ft_putstr(" (");
	ft_putnbr(x);
	ft_putstr(":");
	ft_putnbr(y);
	ft_putstr(")\n");
	return (0);
}

/* int		key_hook(int keycode, t_data *d) */
/* { */
/* 	if (keycode == 65362) */
/* 		move_on(d); */
/* 	else if (keycode == 65364) */
/* 	{ */
/* 		move_back(d); */
/* 		ft_putstr("DOWN\n"); */

/* 		/\*d->y += 10; */
/* 		  d->map->pos->y += 10;*\/ */
/* 	} */
/* 	else if (keycode == 65361) */
/* 	{ */
/* 		turn_left(d); */
/* 		ft_putstr("LEFT\n"); */

/* 		/\*if (d->x > 9) */
/* 		  (d->x) -= 10; */
/* 		  else */
/* 		  (d->x) = 10; */
/* 		  d->map->pos->x -= 10;*\/ */
/* 	} */
/* 	else if (keycode == 65363) */
/* 	{ */
/* 		turn_right(d); */
/* 		ft_putstr("RIGHT\n"); */

/* 		/\*(d->x) += 10; */
/* 		  d->map->pos->x += 10;*\/ */
/* 	} */
/* 	else if (keycode == 65451) */
/* 	{ */
/* 		d->width += 10; */
/* 		d->height += 10; */
/* 	} */
/* 	else if (keycode == 65453) */
/* 	{ */
/* 		d->width -= 10; */
/* 		d->height -= 10; */
/* 	} */
/* 	else if (keycode == 65307) */
/* 		exit(0); */
/* 	else */
/* 	{ */
/* 		ft_putstr("Keycode : "); */
/* 		ft_putnbr(keycode); */
/* 		ft_putchar('\n'); */
/* 	} */
/* 	expose_hook(d); */
/* 	return (0); */
/* } */

int		key_hook(int keycode, t_data *d)
{
	d->i = 0;
	ft_putstr("Keycode : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 65307)
		exit(0);
	if (keycode == UP)
	{
		/*d->p->y += sin(d->alpha) * 10;
		d->p->x += cos(d->alpha) * 10;*/
		d->pos_tmp->y = d->p->y + sin(d->alpha) * 20;
		d->pos_tmp->x = d->p->x + cos(d->alpha) * 20;
		/*d->p->y -= 10;*/
		if (ft_collision(d, d->pos_tmp) == 0)
		{
			d->p->y = d->pos_tmp->y;
			d->p->x = d->pos_tmp->x;
			/*d->p->y -= sin(d->alpha) * 10;
			d->p->x -= cos(d->alpha) * 10;*/
			/*d->p->y += 10;*/
		}
	}
	if (keycode == DOWN)
	{
		/*d->p->y -= sin(d->alpha) * 10;
		d->p->x -= cos(d->alpha) * 10;*/
		d->pos_tmp->y = d->p->y - sin(d->alpha) * 20;
		d->pos_tmp->x = d->p->x - cos(d->alpha) * 20;
		/*d->p->y += 10;*/
		if (ft_collision(d, d->pos_tmp) == 0)
		{
			d->p->y = d->pos_tmp->y;
			d->p->x = d->pos_tmp->x;
			/*d->p->y += sin(d->alpha) * 10;
			d->p->x += cos(d->alpha) * 10;*/
			/*d->p->y -= 10;*/
		}
	}
	if (keycode == RIGHT)
	{
		d->alpha += 0.5;
		/*d->p->x += 10;
		if (ft_collision(d) == -1)
		{
			d->p->x -= 10;
		}*/
	}
	if (keycode == LEFT)
	{
		d->alpha -= 0.5;
		/*d->p->x -= 10;
		if (ft_collision(d) == -1)
		{
			d->p->x += 10;
		}*/
	}
	expose_hook(d);
	return (0);
}

void	ft_mlx(t_data *d)
{
	d->width = SIZE_WINX;
	d->height = SIZE_WINY;
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, SIZE_WINX, SIZE_WINY, "Wolf 3D"); /* Macro in header */
	d->img = mlx_new_image(d->mlx, SIZE_WINX, SIZE_WINY);
	d->data = mlx_get_data_addr(d->img, &d->bbp, &d->sizeline, &d->endian);
	mlx_expose_hook(d->win, expose_hook, d);
	/* mlx_key_hook(d->win, key_hook, d); */
	mlx_hook(d->win, 2, (1L << 0), key_hook, d);
	mlx_mouse_hook(d->win, mouse_hook, d);
	mlx_loop(d->mlx);
}
