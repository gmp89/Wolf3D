/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 14:40:10 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/13 20:32:53 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_char_tab(char **tab)
{
	int		i;

	i = 0;
	while (tab[i] != 0)
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		***tab;
	t_conf	conf;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf [data_file]");
		return (0);
	}
	tab = ft_get_data(argv, &conf);
	ft_print_map(tab);
	return (0);
}
