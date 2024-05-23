/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:19:32 by asel-kha          #+#    #+#             */
/*   Updated: 2024/05/15 11:56:25 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// count the number of words
static int	countwords(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			count++;
		if (str[i] != c && str[i + 1] == '\0')
			count++;
		i++;
	}
	return (count);
}

static void	ft_free(char **str, int c)
{
	while (c >= 0)
	{
		free(str[c]);
		c--;
	}
	free(str);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		l;
	int		r;
	int		e;
	char	**res;

	i = 0;
	e = 0;
	if (!s)
		return (NULL);
	res = ft_calloc((countwords(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (s[i] && e < countwords((char *)s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		l = i;
		while (s[i] && s[i] != c)
			r = ++i;
		res[e] = ft_substr(s, l, r - l);
		if (!res[e++])
			return (ft_free(res, e), NULL);
	}
	return (res);
}
