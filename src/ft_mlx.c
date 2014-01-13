/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 22:42:07 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/14 00:06:39 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_draw(t_data *d)
{
	ft_putstr("ft_draw\n");
	mlx_pixel_put(d->mlx, d->win, 200, 200, 0x00FF00);
}

int		expose_hook(t_data *d)
{
	ft_putstr("expose_hook\n");
	ft_draw(d);
	return (0);
}

int		key_hook(int keycode, t_data *d)
{
	d->i = 0;
	ft_putstr("Keycode : ");
	ft_putnbr(keycode);
	ft_putchar('\n');
	return (0);
}

void	ft_mlx(t_data *d)
{
	ft_putstr("ft_mlx\n");
	d->mlx = mlx_init();
	ft_putstr("1\n");
	d->win = mlx_new_window(d->mlx, SIZE_WINX, SIZE_WINY, "Wolf 3D"); /* Macro in header */
	ft_putstr("2\n");
	ft_putstr("Bla\n");
	mlx_expose_hook(d->mlx, expose_hook, d);
	mlx_key_hook(d->mlx, &key_hook, d);
	ft_draw(d); /* Shouldn't be here */
	ft_putstr("3\n");
	mlx_loop(d->mlx);
}
