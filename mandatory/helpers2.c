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


// int	putnbr_hex


// int    ft_atoi_hex(const char *hexaString)
// {
//     struct s_atoi    var;

//     var.i = 0;
//     var.length = ft_strlen(hexaString);
//     var.startindex = 0;
//     if (var.length > 1 && hexaString[0] == '0' && (hexaString[1] == 'x'
//             || hexaString[1] == 'X'))
//         var.startindex = 2;
//     var.decimalnumber = 0;
//     while (var.i < var.length)
//     {
//         var.currentchar = hexaString[var.i];
//         if (var.currentchar >= '0' && var.currentchar <= '9')
//             var.digitvalue = var.currentchar - '0';
//         else if (var.currentchar >= 'A' && var.currentchar <= 'F')
//             var.digitvalue = var.currentchar - 'A' + 10;
//         else if (var.currentchar >= 'a' && var.currentchar <= 'f')
//             var.digitvalue = var.currentchar - 'a' + 10;
//         var.decimalnumber += var.digitvalue * pow(16, var.length - var.i - 1);
//         var.i++;
//     }
//     return (var.decimalnumber);
// }
