/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 17:50:52 by smabunda          #+#    #+#             */
/*   Updated: 2019/02/26 11:21:10 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "./libft/libft.h"
# include <mlx.h>
# include <time.h>
# include <mlx.h>
# include <math.h>
# include <errno.h>

# define ESC 53
# define NORTH 126
# define SOUTH 125
# define WEST 123
# define EAST 124
# define GREEN 0x00ff00
# define RED 0xff0000
# define BLUE 0x0000ff
# define YELLOW 0xffff00
# define WHITE 0xffffff
# define BLACK 0x0
# define WINW 1024
# define WINH 768
# define LINE (abs(wolf->dx) > abs(wolf->dy) ? abs(wolf->dx) : abs(wolf->dy))

typedef	struct	s_wolf
{
	int			fd;
	char		*line;
	void		*win_ptr;
	void		*mlx_ptr;
	void		*img_ptr;
	char		*img;
	int			width;
	int			height;
	int			dx;
	int			dy;
	int			steps;
	float		x;
	float		y;
	float		xx;
	float		yy;
	double		rayx;
	double		rayy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		posx;
	double		posy;
	int			w;
	int			h;
	double		rdx;
	double		rdy;
	double		odx;
	double		opx;
	int			stepy;
	int			stepx;
	double		sdx;
	double		sdy;
	double		camx;
	int			mapx;
	int			mapy;
	double		ddx;
	double		ddy;
	int			lh;
	int			ds;
	int			de;
	int			color;
	int			side;
	int			hit;
	double		pwd;
	int			**map;
	int			x1;
	char		*fn;
	int			y1;
	int			x2;
	int			y2;
	int			zoom;
	int			col;
	int			row;
	double		angle;
	int			p1[2];
	int			p2[2];
	int			i;
	int			j;
	int			size;
	int			endian;
	int			bpp;
}				t_wolf;

int				ft_buttons(int keycode, t_wolf *param);
void			ft_north(int keycode, t_wolf *param);
void			ft_south(int keycode, t_wolf *param);
void			ft_west(int keycode, t_wolf *param);
void			ft_east(int keycode, t_wolf *param);
int				ft_esc(int keycode, void *param);

void			first(t_wolf *wolf, int x);
void			second(t_wolf *wolf);
void			third(t_wolf *wolf);
void			forth(t_wolf *wolf);
void			ft_rc(t_wolf *wolf);

int				**map_to_array(t_wolf *wolf);
void			ft_size(t_wolf *wolf);
void			mtp(t_wolf *wolf, char **split, char *line);
void			fdp(void **array);

void			ft_draw_line(t_wolf *wolf, int color);
void			drawimg(t_wolf *wolf, int x);
void			put(int x, int y, int size, int bpp, void *img_ptr, int color);

void			ft_error1(t_wolf *wolf);
void			ft_error2(t_wolf *wolf);
void			ft_error3(t_wolf *wolf);
void			ft_errorcol(t_wolf *wolf);
void			ft_errorrow(t_wolf *wolf);

void			ft_wolf(char *a, char *b, char *c);
void			ft_init(t_wolf *wolf, char *a, char *b, char *c);

int				main(int ac, char **av);

#endif
