/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 14:13:16 by smabunda          #+#    #+#             */
/*   Updated: 2019/02/26 11:17:00 by smabunda         ###   ########.fr       */
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
		if (wolf->side == 0)
		{
			if (wolf->rdx > 0)
				wolf->color = RED;
			else
				wolf->color = GREEN;
		}
		else
		{
			if (wolf->rdy > 0)
				wolf->color = YELLOW;
			else
				wolf->color = BLUE;
		}
		drawimg(wolf, x);
		x++;
	}
	mlx_put_image_to_window(wolf->mlx_ptr, wolf->win_ptr, wolf->img_ptr, 0, 0);
	mlx_destroy_image(wolf->mlx_ptr, wolf->img_ptr);
}

void	first(t_wolf *wolf, int x)
{
	wolf->camx = 2 * x / (double)(wolf->w) - 1;
	wolf->rdx = wolf->dirx + wolf->planex * wolf->camx;
	wolf->rdy = wolf->diry + wolf->planey * wolf->camx;
	wolf->mapx = (int)(wolf->posx);
	wolf->mapy = (int)(wolf->posy);
	wolf->ddx = fabs(1 / wolf->rdx);
	wolf->ddy = fabs(1 / wolf->rdy);
}

void	second(t_wolf *wolf)
{
	if (wolf->rdx < 0)
	{
		wolf->stepx = -1;
		wolf->sdx = (wolf->posx - wolf->mapx) * wolf->ddx;
	}
	else
	{
		wolf->stepx = 1;
		wolf->sdx = (wolf->mapx + 1.0 - wolf->posx) * wolf->ddx;
	}
	if (wolf->rdy < 0)
	{
		wolf->stepy = -1;
		wolf->sdy = (wolf->posy - wolf->mapy) * wolf->ddy;
	}
	else
	{
		wolf->stepy = 1;
		wolf->sdy = (wolf->mapy + 1.0 - wolf->posy) * wolf->ddy;
	}
}

void	third(t_wolf *wolf)
{
	wolf->hit = 0;
	while (wolf->hit == 0)
	{
		if (wolf->sdx < wolf->sdy)
		{
			wolf->sdx += wolf->ddx;
			wolf->mapx += wolf->stepx;
			wolf->side = 0;
		}
		else
		{
			wolf->sdy += wolf->ddy;
			wolf->mapy += wolf->stepy;
			wolf->side = 1;
		}
		if (wolf->map[wolf->mapx][wolf->mapy] > 0)
			wolf->hit = 1;
	}
}

void	forth(t_wolf *wolf)
{
	if (wolf->side == 0)
		wolf->pwd = (wolf->mapx - wolf->posx + (1 - wolf->stepx) / 2) \
		   	/ wolf->rdx;
	else
		wolf->pwd = (wolf->mapy - wolf->posy + (1 - wolf->stepy) / 2) \
			/ wolf->rdy;
	if (wolf->pwd > 0.0)
		wolf->lh = (int)(wolf->h / wolf->pwd);
	wolf->ds = -wolf->lh / 2 + wolf->h / 2;
	if (wolf->ds < 0)
		wolf->ds = 0;
	wolf->de = wolf->lh / 2 + wolf->h / 2;
	if (wolf->de >= wolf->h)
		wolf->de = wolf->h - 1;
}
