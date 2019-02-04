/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:39:48 by smabunda          #+#    #+#             */
/*   Updated: 2018/07/05 11:39:51 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		is_neg;
	int		nbr;

	i = 0;
	nbr = 0;
	is_neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		is_neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		nbr *= 10;
		nbr += ((int)(str[i]) - '0');
		i++;
	}
	return (nbr * is_neg);
}
