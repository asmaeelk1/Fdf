#include "../includes/fdf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

int	ft_putnbr_hex(unsigned long c, char start)
{
	int	countlen;

	countlen = 0;
	if (c > 15)
	{
		countlen += ft_putnbr_hex(c / 16, start);
		countlen += ft_putnbr_hex(c % 16, start);
	}
	else if (c <= 9)
		countlen += ft_putchar(48 + c);
	else
		countlen += ft_putchar(start + c - 10);
	return (countlen);
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

char *ft_strtok(char *str, char del)
{
    int i;
    static char *line;
    char *token;

    (1) && (i = 0);
    token = ft_calloc(50, 1);
    if(str)
        line = ft_strdup(str);
    while(*line == del)
        line++;
    while(*line && *line != del)
    {
    
        token[i] = *line;
        i++;
        line++;
    }
    token[i] = '\0';
    return(token);
}