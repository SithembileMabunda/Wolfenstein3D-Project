/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:44:31 by smabunda          #+#    #+#             */
/*   Updated: 2018/07/05 11:44:39 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*cu;

	i = 0;
	cu = (unsigned char *)b;
	while (i < len)
	{
		cu[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
