/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:19:32 by asel-kha          #+#    #+#             */
/*   Updated: 2024/07/14 20:45:51 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// count the number of words
int	countwords(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == ' ' || !str[i + 1]))
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
	int		e;
	char	**res;

	e = 0;
	if (!s)
		return (NULL);
	res = ft_calloc((countwords(s, c) + 1), sizeof(char *));
	if (!res)
		return (NULL);
	while (countwords(s, c))
	{
		i = 0;
		while (*s && *s == c)
			s++;
		while (s[i] && s[i] != c)
			i++;
		res[e] = ft_calloc((i + 1), 1);
		ft_strlcpy(res[e], s, i + 1);
		if (!res[e++])
			return (ft_free(res, e), NULL);
		s += i;
	}
	return (res);
}
