/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:54:10 by asel-kha          #+#    #+#             */
/*   Updated: 2024/07/12 03:00:52 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	ft_atoi(const char *str, t_x **x)
{
	int		i;
	long	nbr;
	int		signe;

	(1) && (i = 0, signe = 1, nbr = 0);
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '-')
		(1) && (signe = -1) && (i++);
	// if (!str[i])
	// 	(puts("here")) && (fatal(BAD_ARG), 0) ;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		(1) && (nbr = nbr * 10, nbr += str[i] - 48, i++);
	if (nbr > INT32_MAX || nbr * signe < INT32_MIN)
		(free_struct_lines(x), fatal(BAD_ARG));
	if (str[i] && (str[i] < '0' || str[i] > '9') && str[i] != '\n')
		(free_struct_lines(x), puts("here"), fatal(BAD_ARG));
	free((char *)str);
	return (nbr * signe);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

int	putnbr_hex(char *hex)
{
	int	i;
	int	hex_res;

	hex_res = 0;
	i = 0;
	if (hex[i] == '0' && (hex[i + 1] == 'x' || hex[i + 1] == 'X'))
		i = 2;
	else
		fatal(INVALID_FILE);
	while (hex[i])
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			hex_res = hex_res * 16 + (hex[i] - 48);
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			hex_res = hex_res * 16 + (hex[i] - 'a' + 10);
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			hex_res = hex_res * 16 + (hex[i] - 'A' + 10);
		i++;
	}
	hex_res = hex_res * 16 + 15;
	hex_res = hex_res * 16 + 15;
	return (hex_res);
}
