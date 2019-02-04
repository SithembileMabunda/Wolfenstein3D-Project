/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buttons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 18:26:40 by smabunda          #+#    #+#             */
/*   Updated: 2018/10/16 13:41:32 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_buttons(int keycode, t_wolf *param)
{
	printf("%d\n", keycode);
	if (keycode == ESC)
		ft_esc(keycode, param);
	if (keycode == NORTH)
		ft_north(keycode, param);
	if (keycode == SOUTH)
		ft_south(keycode, param);
	if (keycode == WEST)
		ft_west(keycode, param);
	if (keycode == EAST)
		ft_east(keycode, param);
	return (0);
}

void	ft_north(int keycode, t_wolf *wolf)
{
	(void)keycode;
	if (wolf->map[(int)(wolf->posx +
				(*wolf).dirx * 0.5)][(int)(wolf->posy)] == 0)
		wolf->posx += wolf->dirx * 0.5;
	if (wolf->map[(int)(wolf->posx)]
			[(int)(wolf->posy + wolf->diry * 0.5)] == 0)
		wolf->posy += wolf->diry * 0.5;
	mlx_clear_window(wolf->mlx_ptr, wolf->win_ptr);
	ft_rc(wolf);
}

void	ft_south(int keycode, t_wolf *wolf)
{
	(void)keycode;
	if (wolf->map[(int)(wolf->posx -
				(*wolf).dirx * 0.5)][(int)(wolf->posy)] == 0)
		wolf->posx -= wolf->dirx * 0.5;
	if (wolf->map[(int)(wolf->posx)]
			[(int)(wolf->posy - wolf->diry * 0.5)] == 0)
		wolf->posy -= wolf->diry * 0.5;
	mlx_clear_window(wolf->mlx_ptr, wolf->win_ptr);
	ft_rc(wolf);
}

void	ft_west(int keycode, t_wolf *wolf)
{
	(void)keycode;
	wolf->odx = wolf->dirx;
	wolf->dirx = wolf->dirx * cos(wolf->angle)
		- wolf->diry * sin(wolf->angle);
	wolf->diry = wolf->odx * sin(wolf->angle)
		+ wolf->diry * cos(wolf->angle);
	wolf->opx = wolf->planex;
	wolf->planex = wolf->planex * cos(wolf->angle)
		- wolf->planey * sin(wolf->angle);
	wolf->planey = wolf->opx * sin(wolf->angle)
		+ wolf->planey * cos(wolf->angle);
	mlx_clear_window(wolf->mlx_ptr, wolf->win_ptr);
	ft_rc(wolf);
}

void	ft_east(int keycode, t_wolf *wolf)
{
	(void)keycode;
	wolf->odx = wolf->dirx;
	wolf->dirx = wolf->dirx * cos(-wolf->angle)
		- wolf->diry * sin(-wolf->angle);
	wolf->diry = wolf->odx * sin(-wolf->angle)
		+ wolf->diry * cos(-wolf->angle);
	wolf->opx = wolf->planex;
	wolf->planex = wolf->planex * cos(-wolf->angle)
		- wolf->planey * sin(-wolf->angle);
	wolf->planey = wolf->opx * sin(-wolf->angle)
		+ wolf->planey * cos(-wolf->angle);
	mlx_clear_window(wolf->mlx_ptr, wolf->win_ptr);
	ft_rc(wolf);
}
