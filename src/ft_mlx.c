/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 22:42:07 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/14 14:09:37 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_draw(t_data *d)
{
	mlx_pixel_put(d->mlx, d->win, 200, 200, 0x00FF00);
}

int		expose_hook(t_data *d)
{
	ft_draw(d);
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

int		key_hook(int keycode, t_data *d)
{
	d->i = 0;
	ft_putstr("Keycode : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 65307)
		exit(0);
	return (0);
}

void	ft_mlx(t_data *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, SIZE_WINX, SIZE_WINY, "Wolf 3D"); /* Macro in header */
	mlx_key_hook(d->win, key_hook, d);
	mlx_mouse_hook(d->win, mouse_hook, d);
	mlx_expose_hook(d->win, expose_hook, d);
	mlx_loop(d->mlx);
}
