/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:32:32 by asel-kha          #+#    #+#             */
/*   Updated: 2024/05/08 01:35:11 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		start = ft_strlen(s);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	while (s[start] && i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}


char	*ft_strdup(const char *s1)
{
	char	*ptr;

	ptr = malloc(ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, ft_strlen(s1) + 1);
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	if ((int)size < 0 || (int)count < 0)
		return (NULL);
	tmp = malloc(count * size);
	if (!tmp)
		exit(EXIT_FAILURE);
	while (i < (count * size))
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}


char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*rtn;
	int		i;
	int		e;

	e = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	rtn = malloc(ft_strlen(s1) + ft_strlen(s2) + e * sizeof(char));
	if (!rtn)
		return (NULL);
	while (s1[i])
		rtn[e++] = s1[i++];
	i = 0;
	while (s2[i])
		rtn[e++] = s2[i++];
	rtn[e] = '\0';
	return (rtn);
}
