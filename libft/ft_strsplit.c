/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smabunda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:55:47 by smabunda          #+#    #+#             */
/*   Updated: 2018/07/05 11:56:30 by smabunda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_wordlen(char const *s, char c)
{
	int i;
	int wordlen;

	i = 0;
	wordlen = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		wordlen++;
		i++;
	}
	return (wordlen);
}

static	int		ft_wordnbr(char const *s, char c)
{
	int i;
	int wordnbr;

	i = 0;
	wordnbr = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			wordnbr++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wordnbr);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**p;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	p = (char **)malloc(sizeof(char *) * (ft_wordnbr(s, c) + 1));
	if (p == NULL)
		return (NULL);
	while (i < ft_wordnbr(s, c))
	{
		j = 0;
		p[i] = ft_strnew(ft_wordlen(&s[k], c));
		while (s[k] && s[k] == c)
			k++;
		while (s[k] && s[k] != c)
			p[i][j++] = s[k++];
		i++;
	}
	p[i] = NULL;
	return (p);
}
