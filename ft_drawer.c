/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:42:28 by smabunda          #+#    #+#             */
/*   Updated: 2018/10/19 16:38:15 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void    ft_draw_line(t_wolf *wolf, int color)
{
	int i;

	wolf->x1 = wolf->p1[0];
	wolf->x2 = wolf->p2[0];
	wolf->y1 = wolf->p1[1];
	wolf->y2 = wolf->p2[1];
	wolf->dx = wolf->x2 - wolf->x1;
	wolf->dy = wolf->y2 - wolf->y1;
	wolf->steps = LINE;
	wolf->xx = wolf->dx / (float)(wolf->steps);
	wolf->yy = wolf->dy / (float)(wolf->steps);
	wolf->x = wolf->x1;
	wolf->y = wolf->y1;
	i = 0;
	while (i < wolf->steps)
	{
		mlx_pixel_put(wolf->mlx_ptr, wolf->win_ptr, wolf->x, wolf->y, color);
		wolf->x = wolf->x + wolf->xx;
		wolf->y = wolf->y + wolf->yy;
		i++;
	}
}

void	put(int x, int y, int size, int bpp, void *img_ptr, int color)
{
	if (x >= 0 && x < WINW && y >= 0 && y < WINH)
	{
		*(unsigned int*)(img_ptr + (bpp * x + y * size)) = color;
	}
}

void    drawimg(t_wolf *wolf, int x1)
{
	int dx = x1 - x1;
	int dy = wolf->de - wolf->ds;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float xx = dx / (float)steps;
	float yy = dy / (float)steps;

	float x = x1;
	float y = wolf->ds;
	int i = 0;
	while (i <= steps)
	{
		put(x, y, wolf->size, wolf->bpp, wolf->img, wolf->color);
		x += xx;
		y += yy;
		i++;
	}
}
