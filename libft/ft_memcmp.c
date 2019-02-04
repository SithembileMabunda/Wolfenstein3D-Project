/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:43:47 by smabunda          #+#    #+#             */
/*   Updated: 2018/07/05 11:43:50 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*c1;
	unsigned char		*c2;

	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	while (n > 0)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		else
			c1++;
		c2++;
		n--;
	}
	return (0);
}
