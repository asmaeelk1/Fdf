#include "../includes/fdf.h"

t_map	*ft_lstnew_map(t_x *axis)
{
	t_map	*node;

	node = malloc(sizeof(t_map));
	if (!node)
		return (NULL);
	node->lines = axis;
	node->next = NULL;
	return (node);
}

t_map	*ft_lstlast_map(t_map **map)
{
	t_map *tmp = *map;
	if (!tmp)
		return (NULL);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_lstadd_back_map(t_map **map, t_x *new)
{

	t_map	*last;

	if (!map && !(*map)) {
		*map = ft_lstnew_map(new);
		return;
	}
	last = ft_lstlast_map(map);
	if(!last)
		*map = ft_lstnew_map(new);
	else
		last->next = ft_lstnew_map(new);
}

int	ft_lstsize_map(t_map **map)
{
	int		count;
	t_map	*tmp;

	tmp = *map;
	count = 0;
	while (tmp)
		(1) && (count++, tmp = tmp->next);
	return (count);
}
