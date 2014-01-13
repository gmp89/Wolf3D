/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 19:28:57 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/13 21:36:55 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_config(t_conf *conf)
{
	ft_putnbr(conf->x);
	ft_putchar('\n');
	ft_putnbr(conf->y);
	ft_putchar('\n');
	ft_putstr(conf->name);
	ft_putchar('\n');
	ft_putnbr(conf->wall);
	ft_putchar('\n');
	ft_putnbr(conf->empty);
	ft_putchar('\n');
	ft_putnbr(conf->start);
	ft_putchar('\n');
}

void	ft_set_conf(t_conf *conf, int fd)
{
	char	*line;
	char	**tab;
	int		i;

	i = 0;
	conf->x = 0;
	get_next_line(fd, &line);
	free(line);
	tab = ft_strsplit(line, ' ');
	conf->x = ft_atoi(tab[0]);
	conf->y = ft_atoi(tab[1]);
	conf->name = ft_strdup(tab[2]);
	conf->wall = ft_atoi(tab[3]);
	conf->empty = ft_atoi(tab[4]);
	conf->start = ft_atoi(tab[5]);
	close(fd);
	free(tab);
}

int		**ft_fill_tab(char *line, t_conf *conf)
{
	int		**tab;
	int		*tmp;
	char	**text;
	int		i;

	i = 0;
	tab = (int **)malloc(sizeof(int *) * (conf->x + 1));
	tmp = (int *)malloc(sizeof(int) * (conf->x + 1));
	text = ft_strsplit(line, ' ');
	while (i < conf->x)
	{
		tmp[i] = ft_atoi(text[i]);
		tab[i] = &tmp[i];
		i++;
	}
	tab[i] = NULL;
	/* free(text); */
	return (tab);
}

void	ft_print_map(int ***map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i] != NULL)
	{
		while (map[i][j] != NULL)
		{
			ft_putnbr(*map[i][j]);
			ft_putchar(' ');
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}

int		***ft_get_data(char **av, t_conf *conf)
{
	int		fd;
	char	*line;
	int		i;
	int		***tab;

	i = 0;
	fd = open(av[1], O_RDONLY);
	ft_set_conf(conf, fd);
	tab = (int ***)malloc(sizeof(int **) * (conf->y + 1));
	while (get_next_line(fd, &line) > 0)
	{
		tab[i] = (int **)malloc(sizeof(int *) * conf->x);
		tab[i] = ft_fill_tab(line, conf);
		i++;
		free(line);
	}
	close(fd);
	tab[i] = NULL;
	return (tab);
}
