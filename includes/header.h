/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 17:19:43 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/14 22:05:15 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define SIZE_WINX 768
# define SIZE_WINY 768
# define GREY 0x868686
# define BLUE 0x0893CF
# define DBLUE 0x437FA9
# define YELLOW 0xE9D25E
# define ORANGE 0xDB7A39
# define GREEN 0x79C19E

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

typedef struct		s_win
{
	int				x;
	int				y;
	int				grid_x;
	int				grid_y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			cam_x;
	double			ray_pos_x;
	double			ray_pos_y;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			dist_wall_x;
	double			dist_wall_y;
	double			dist2_wall_x;
	double			dist2_wall_y;
	double			wall_lenght;
}					t_win;

typedef struct		s_data
{
	int				***map;
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bbp;
	int				sizeline;
	int				endian;
	int				i;
	t_win			*wi;
}					t_data;

int		***ft_get_data(char **av, t_conf *conf);
void	ft_set_conf(t_conf *conf, int fd);
void	print_config(t_conf *conf);
int		**ft_fill_tab(char *line, t_conf *conf);
void	ft_print_map(int ***map);
void	ft_mlx(t_data *d);
int		expose_hook(t_data *d);
void	ft_put_pixel_to_img(t_data *d, int x, int y, int color);
int		key_hook(int keycode, t_data *d);
void	ft_draw(t_data *d);
void	ft_draw_background(t_data *d);

#endif
