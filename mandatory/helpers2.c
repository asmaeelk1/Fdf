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
	if (!str[i])
		fatal(BAD_ARG);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		(1) && (nbr = nbr * 10, nbr += str[i] - 48, i++);
	if(nbr > INT32_MAX || nbr * signe < INT32_MIN)
		(free_struct(x), fatal(BAD_ARG));
	if (str[i] && (str[i] < '0' || str[i] > '9') && str[i] != '\n')
		(free_struct(x), fatal(BAD_ARG));
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

