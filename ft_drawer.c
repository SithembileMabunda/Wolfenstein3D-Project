/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:42:28 by smabunda          #+#    #+#             */
/*   Updated: 2019/02/26 14:18:02 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

//void	put(int x, int y, void img_ptr, int size, int bpp, t_wolf *wolf)
void	put(int x, int y, void *img_ptr, int size, int bpp, t_wolf *wolf)
{
	if (x >= 0 && x < WINW && y >= 0 && y < WINH)
	{
		*(unsigned int*)(img_ptr + \
				(bpp * x + y * size)) = wolf->color;
		//*(unsigned int*)(img_ptr + 
//				(wolf->bpp * x + y * wolf->size)) = wolf->color;
	}
}

void	drawimg(t_wolf *wolf, int x1)
{
	int i;

	wolf->dx = x1 - x1;
	wolf->dy = wolf->de - wolf->ds;
	wolf->steps = abs(wolf->dx) > abs(wolf->dy) ? \
		abs(wolf->dx) : abs(wolf->dy);
	wolf->xx = wolf->dx / (float)wolf->steps;
	wolf->yy = wolf->dy / (float)wolf->steps;
	wolf->x = x1;
	wolf->y = wolf->ds;
	i = 0;
	while (i <= wolf->steps)
	{
		//put(wolf->x, wolf->y, wolf->img_ptr, wolf);
		put(wolf->x, wolf->y, wolf->img, wolf->size, wolf->bpp, wolf);
		//put(wolf->x, wolf->y, wolf->img_ptr, wolf);
		wolf->x += wolf->xx;
		wolf->y += wolf->yy;
		i++;
	}
}
