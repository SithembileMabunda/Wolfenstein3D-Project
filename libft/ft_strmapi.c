/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:54:29 by smabunda          #+#    #+#             */
/*   Updated: 2018/07/05 11:54:31 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	size;
	size_t	i;
	char	*snew;

	if (s == NULL)
		return (NULL);
	size = 0;
	i = 0;
	snew = NULL;
	size = ft_strlen((char*)s);
	snew = (char*)malloc((sizeof(char) * size) + 1);
	if (snew == NULL)
		return (NULL);
	while (i < size)
	{
		snew[i] = (*f)(i, s[i]);
		i++;
	}
	snew[i] = '\0';
	return (snew);
}
