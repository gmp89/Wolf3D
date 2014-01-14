/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 17:19:43 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/14 13:51:52 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define SIZE_WINX 720
# define SIZE_WINY 720

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "libft.h"

typedef struct		s_conf
{
	int				x;
	int				y;
	char			*name;
	int				wall;
	int				empty;
	int				start;
}					t_conf;

typedef struct		s_data
{
	void			*mlx;
	void			*win;
	int				i;
}					t_data;

int		***ft_get_data(char **av, t_conf *conf);
void	ft_set_conf(t_conf *conf, int fd);
void	print_config(t_conf *conf);
int		**ft_fill_tab(char *line, t_conf *conf);
void	ft_print_map(int ***map);
void	ft_mlx(t_data *d);
int		expose_hook(t_data *d);
void	ft_draw(t_data *d);
int		key_hook(int keycode, t_data *d);

#endif
