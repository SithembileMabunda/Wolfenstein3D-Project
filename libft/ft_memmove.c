/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:44:21 by smabunda          #+#    #+#             */
/*   Updated: 2018/07/05 11:44:23 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned char		*s;
	size_t				i;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (s < d)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	else
	{
		while (i < n)
		{
			if (d[i] != s[i])
				d[i] = s[i];
			i++;
		}
	}
	return (dst);
}
