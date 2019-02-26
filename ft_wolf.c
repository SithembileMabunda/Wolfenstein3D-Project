/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:10:53 by smabunda          #+#    #+#             */
/*   Updated: 2019/02/26 12:14:24 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_rc(t_wolf *wolf)
{
	int		x;

	x = 0;
	wolf->img_ptr = mlx_new_image(wolf->mlx_ptr, WINW, WINW);
	wolf->img = mlx_get_data_addr(wolf->img_ptr, &wolf->bpp, \
			&wolf->size, &wolf->endian);
	wolf->bpp /= 8;
	while (x < wolf->w)
	{
		first(wolf, x);
		second(wolf);
		third(wolf);
		forth(wolf);
		fifth(wolf);
		drawimg(wolf, x);
		x++;
	}
	mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr, wolf->img_ptr, 0, 0);
	mlx_destroy_image(wolf->mlx_ptr, wolf->img_ptr);
}

void	ft_init(t_wolf *wolf, char *a, char *b, char *c)
{
	wolf = (t_wolf *)malloc(sizeof(t_wolf));
	wolf->fd = open(a, O_RDONLY);
	ft_error1(wolf);
	wolf->mlx_ptr = mlx_init();
	wolf->win_ptr = mlx_new_window(wolf->mlx_ptr, WINW, WINH, "Wolfenstein 3D");
	wolf->fn = a;
	wolf->map = map_to_array(wolf);
	wolf->h = WINH;
	wolf->w = WINW;
	(*wolf).posx = atof(b) + 0.1;
	(*wolf).posy = atof(c) + 0.1;
	ft_error3(wolf);
	(*wolf).dirx = -1;
	(*wolf).diry = 0;
	wolf->angle = 0.2;
	(*wolf).planex = 0;
	(*wolf).planey = 0.66;
	ft_error2(wolf);
	ft_rc(wolf);
	mlx_hook(wolf->win_ptr, 2, 0, ft_buttons, wolf);
	mlx_loop(wolf->mlx_ptr);
	fdp((void**)wolf->map);
	free(&wolf);
	close(wolf->fd);
}

void	ft_wolf(char *a, char *b, char *c)
{
	t_wolf	*wolf;

	wolf = NULL;
	ft_init(wolf, a, b, c);
}
