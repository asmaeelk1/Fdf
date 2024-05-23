#include "../includes/fdf.h"

void	ft_putstr_fd(const char *s, int fd)
{
	if (fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	fatal(const char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
}

void	free_struct(t_x **x)
{
	t_x	*ptr;
	t_x	*tmp;

	tmp = *x;
	while (tmp)
	{
		ptr = tmp;
		tmp = tmp->next;
		free(ptr);
	}
}