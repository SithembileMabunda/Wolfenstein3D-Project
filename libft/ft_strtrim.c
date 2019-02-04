/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:56:59 by smabunda          #+#    #+#             */
/*   Updated: 2018/07/05 11:57:06 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*snew;
	unsigned int	i;
	size_t			len;
	size_t			j;

	snew = NULL;
	i = 0;
	len = 0;
	j = 1;
	if (s == NULL)
		return (NULL);
	len = ft_strlen((char*)s);
	while (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[len - j] == ' ' || s[len - j] == ',' || s[len - j] == '\n' || \
			s[len - j] == '\t')
		j++;
	if (s[i] == '\0')
		j = 0;
	else
		j--;
	snew = ft_strsub(s, i, len - j - i);
	if (snew == NULL)
		return (NULL);
	return (snew);
}
