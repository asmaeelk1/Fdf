/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:19:32 by asel-kha          #+#    #+#             */
/*   Updated: 2024/07/13 22:50:16 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

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

// int	countwords(char *str, char c)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	while (str[i] && str[i] == c)
// 		i++;
// 	while (str[i])
// 	{
// 		if (str[i] == c && str[i + 1] != c)
// 			count++;
// 		if (str[i] != c && str[i + 1] == '\0')
// 			count++;
// 		i++;
// 	}
// 	return (count);
// }

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
		ft_strlcpy(res[e], s, i+1);
		if (!res[e++])
			return (ft_free(res, e), NULL);
		s += i;
	}
	return (res);
}

// static int	count_str(char const *s, char c)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = 0;
// 	while (s[i])
// 	{
// 		if (s[i] != c && ((i && s[i - 1] == c) || i == 0))
// 			len++;
// 		i++;
// 	}
// 	return (len);
// }

// static void	*free_arr(char **s, int j)
// {
// 	while (j >= 0)
// 	{
// 		free(s[j]);
// 		j--;
// 	}
// 	free(s);
// 	return (NULL);
// }

// char	**ft_split(char *s, char c)
// {
// 	int		i;
// 	int		j;
// 	char	**ptr2;

// 	if (!s)
// 		return (NULL);
// 	ptr2 = ft_calloc((count_str(s, c) + 1), sizeof(char *));
// 	if (ptr2 == NULL)
// 		return (NULL);
// 	j = 0;
// 	while (count_str(s, c))
// 	{
// 		i = 0;
// 		while (s[i] == c && s[i] != '\0')
// 			s++;
// 		while (s[i] != c && s[i] != '\0')
// 			i++;
// 		ptr2[j] = ft_calloc((i + 1), 1);
// 		if (ptr2[j] == NULL)
// 			return (free_arr(ptr2, j));
// 		ft_strlcpy(ptr2[j], s, i + 1);
// 		j++;
// 		s += i;
// 	}
// 	return (ptr2);
// }

// char	**ft_split(char *s, char c)
// {
// 	int		j;
// 	char	**ptr;
// 	char	*token;
// 	int		count;

// 	count = countwords(s, c);
// 	printf("---->%d\n", countwords(s, c));
// 	if (!s )
// 		return (NULL);
// 	ptr = ft_calloc((count + 1) , sizeof(char *));
// 	if (ptr == NULL)
// 		return (NULL);
// 	j = 0;
// 	token = ft_strtok(s, c);
// 	while (token)
// 	{
// 		ptr[j++] = ft_strdup(token);
// 		token = ft_strtok(NULL, c);
// 	}
// 	ptr[j] = token;
// 	return (ptr);
// }