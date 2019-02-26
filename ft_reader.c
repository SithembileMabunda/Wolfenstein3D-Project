/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 13:42:58 by smabunda          #+#    #+#             */
/*   Updated: 2019/02/26 11:11:14 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	fdp(void **array)
{
	int n;

	n = 0;
	while (array[n])
	{
		free(array[n]);
		n++;
	}
	free(array);
}

void	mtp(t_wolf *wolf, char **split, char *line)
{
	wolf->row++;
	wolf->col = 0;
	split = ft_strsplit(line, ' ');
	while (split[wolf->col])
		wolf->col++;
	if (wolf->row == 1)
		wolf->width = wolf->col;
	fdp((void **)split);
	if (wolf->width != wolf->col)
	{
		ft_putstr("Map Error : Line Width Are Not Equal\n");
		exit(0);
	}
}

void	ft_size(t_wolf *wolf)
{
	char	**split;
	char	*line;

	split = NULL;
	if ((wolf->fd = open(wolf->fn, O_RDONLY)) < 0)
	{
		ft_putstr(strerror(errno));
		ft_putchar('\n');
		exit(0);
	}
	wolf->row = 0;
	while (get_next_line(wolf->fd, &line) == 1)
	{
		mtp(wolf, split, line);
		free(line);
	}
	wolf->height = wolf->row;
	if (wolf->width == 0 || wolf->height == 0)
	{
		ft_putstr("File Is Empty\n");
		exit(0);
	}
}

int		**map_to_array(t_wolf *wolf)
{
	int		**array;
	char	**s;

	wolf->i = 0;
	ft_size(wolf);
	wolf->fd = open(wolf->fn, O_RDONLY);
	array = (int **)malloc(sizeof(int *) * (wolf->height) + 1);
	while (get_next_line(wolf->fd, &wolf->line) > 0)
	{
		wolf->j = 0;
		s = ft_strsplit(wolf->line, ' ');
		array[wolf->i] = (int *)malloc(sizeof(int) * (wolf->width) + 1);
		while (s[wolf->j])
		{
			array[wolf->i][wolf->j] = ft_atoi(s[wolf->j]);
			wolf->j++;
		}
		free(wolf->line);
		array[wolf->i][wolf->j] = '\0';
		fdp((void **)s);
		wolf->i++;
	}
	array[wolf->i] = NULL;
	close(wolf->fd);
	return (array);
}
