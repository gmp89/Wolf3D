/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/13 17:19:43 by gpetrov           #+#    #+#             */
/*   Updated: 2014/01/18 18:25:15 by gpetrov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define PI 3.141593
# define SIZE_WINX 720
# define SIZE_WINY 720
# define WHITE 0xFFFFFF
# define GREY 0x868686
# define BLUE 0x0893CF
# define DBLUE 0x437FA9
# define YELLOW 0xE9D25E
# define ORANGE 0xDB7A39
# define GREEN 0x79C19E
# define SIZE_BLOCK 100
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define FOV_X 320
# define FOV_Y 200
# define START_X 100
# define START_Y 100
# define RAD 0.017453292519943
# define FOV 60
# define RM ((SIZE_WINX / d->p->y) / 5)

#include <stdio.h>

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
}					t_win;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_line
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	t_point			a;
	t_point			b;
}					t_line;

typedef struct		s_hit
{
	int				face;
	double			dist;
}					t_hit;

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
	int				wall;
	int				empty;
	int				col;
	int				li;
	double			alpha;

	int				width;
	int				height;
	t_point			*pos_tmp;
	t_hit			*hit;
	t_point			*pos;
	t_point			*p;
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
void	ft_trace_line(t_data *d, t_point *a, t_point *b, int color);
void	ft_swap_pos(t_point *a, t_point *b);
void	ft_trace_block(t_data *d, int x, int y);
void	ft_clean(t_data *d);
void	draw_map(t_data *d);
int		ft_collision(t_data *d, t_point *pos);
void	ft_raytrace(t_data *d);
void	draw_player(t_data *d);
void	ft_raycast(t_data *d);
void	search_wall(t_data *d, double alpha, t_hit *hit);
void	ft_raycast(t_data *d);
void	ft_print_wolf(t_data *d, int dist, double dist_screen, int i);
void	move_on(t_data *d);
void	turn_right(t_data *d);
void	move_back(t_data *d);
void	turn_left(t_data *d);

#endif
