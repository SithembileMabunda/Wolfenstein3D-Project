/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:55:37 by smabunda          #+#    #+#             */
/*   Updated: 2018/07/05 11:55:38 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len;

	len = ft_strlen((char *)s);
	while (s[len] != (char)c && len != 0)
		len--;
	if (s[len] == (char)c)
		return ((char*)&s[len]);
	return (NULL);
}
