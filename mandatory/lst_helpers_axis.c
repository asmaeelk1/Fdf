#include "../includes/fdf.h"


t_x	*ft_lstnew_axis(int altitude)
{
	t_x	*node;

	node = malloc(sizeof(t_x));
	if (!node)
		return (NULL);
	node->altitude = altitude;
	node->next = NULL;
	return (node);
}

t_x	*ft_lstlast_axis(t_x *x)
{
	t_x *tmp = x;
	if (!tmp)
		return (NULL);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_lstadd_back_axis(t_x **x, t_x *new)
{
	t_x	*last;

	if (!x && !*x)
	{
		*x = new;
		return ;
	}
	last = ft_lstlast_axis(*x);
	if (!last)
	{
		*x = new;
		return ;
	}
	last->next = new;
}


int	ft_lstsize_axis(t_x **x)
{
	int		count;
	t_x	*tmp;

	tmp = *x;
	count = 0;
	while (tmp)
		(1) && (count++, tmp = tmp->next);
	return (count);
}
