/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:56:40 by smabunda          #+#    #+#             */
/*   Updated: 2018/07/05 11:56:41 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] != '\0' && s2[j] != '\0')
		{
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		else
		{
			i++;
		}
	}
	return (0);
}
