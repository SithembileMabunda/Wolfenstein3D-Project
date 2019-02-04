/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 15:04:11 by smabunda          #+#    #+#             */
/*   Updated: 2018/10/16 16:28:02 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_error1(t_wolf *wolf)
{
	if (wolf->fd <= 0)
	{
		ft_putstr(strerror(errno));
		ft_putchar('\n');
		exit(0);
	}
}

void	ft_error2(t_wolf *wolf)
{
	if (wolf->map[(int)wolf->posx][(int)wolf->posy] != 0)
	{
		ft_putstr("Starting Position Invalid\n");
		exit(0);
	}
}

void	ft_error3(t_wolf *wolf)
{
	if (wolf->posx >= wolf->row)
	{
		ft_putstr("Starting Position Invalid\n");
		exit(0);
	}
	if (wolf->posy >= wolf->col)
	{
		ft_putstr("Starting Position Invalid\n");
		exit(0);
	}
}

void	ft_errorcol(t_wolf *wolf)
{
	int i;

	i = 0;
	while (i != wolf->col)
	{
		if (wolf->map[0][i] == 0)
		{
			ft_putstr("Invalid Map : Wall Error\n");
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i != wolf->col)
	{
		if (wolf->map[wolf->row][i] == 0)
		{
			ft_putstr("Invalid Map : Wall Error\n");
			exit(0);
		}
		i++;
	}
}

void	ft_errorrow(t_wolf *wolf)
{
	int i;

	i = 0;
	while (i != wolf->row)
	{
		if (wolf->map[i][0] == 0)
		{
			ft_putstr("Invalid Map : Wall Error\n");
			exit(0);
		}
		i++;
	}
	i = 0;
	while (i != wolf->row)
	{
		if (wolf->map[i][wolf->col] == 0)
		{
			ft_putstr("Invalid Map : Wall Error\n");
			exit(0);
		}
		i++;
	}
}
