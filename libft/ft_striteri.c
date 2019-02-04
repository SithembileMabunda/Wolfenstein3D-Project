/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:53:39 by smabunda          #+#    #+#             */
/*   Updated: 2018/07/05 11:53:41 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int i;
	int j;

	i = 0;
	if (s != NULL && *f != NULL)
	{
		j = ft_strlen(s);
		while (i < j)
		{
			(*f)(i, &s[i]);
			i++;
		}
	}
}
