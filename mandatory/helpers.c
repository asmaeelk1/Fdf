/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:53:55 by asel-kha          #+#    #+#             */
/*   Updated: 2024/07/14 00:49:08 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strtok(char *str, char del)
{
	int			i;
	static char	*line;
	char		*token;

	(1) && (i = 0);
	token = ft_calloc(50, 1);
	if (str)
		line = str;
	while (*line && *line == del)
		line++;
	while (*line && *line != del)
	{
		token[i] = *line;
		i++;
		line++;
	}
	token[i] = '\0';
	return (token);
}

// bool	find_c(const char sep, char c)
// {
// 		if (sep == c)
// 			return (true);
// 	return (false);
// }

// char	*ft_strtok(char *str, char sep)
// {
// 	static char	*hold;
// 	char		*token;

// 	if (str)
// 		hold = str;
// 	if (!hold || !*hold)
// 		return (NULL);
// 	while (*hold && find_c(sep, *hold))
// 		hold++;
// 	if (!*hold)
// 		return (NULL);
// 	token = hold;
// 	while (*hold && !find_c(sep, *hold))
// 		hold++;
// 	if (*hold)
// 		*hold++ = 0;
// 	return (token);
// }
