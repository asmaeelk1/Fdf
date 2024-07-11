/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_helpers_axis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:54:33 by asel-kha          #+#    #+#             */
/*   Updated: 2024/07/09 14:54:35 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_x	*ft_lstnew_axis(int altitude, int x, int y, char *color)
{
	t_x	*node;

	node = malloc(sizeof(t_x));
	if (!node)
		return (NULL);
	node->y = y;
	node->altitude = altitude;
	node->next = NULL;
	if (*color != '\0')
		node->color = putnbr_hex(color);
	else if (node->altitude > 0)
		node->color = putnbr_hex("0xff00ff");
	else
		node->color = putnbr_hex("0xffffff");
	node->x = x;
	return (node);
}

t_x	*ft_lstlast_axis(t_x *x)
{
	t_x	*tmp;

	tmp = x;
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
	int	count;
	t_x	*tmp;

	tmp = *x;
	count = 0;
	while (tmp)
		(1) && (count++, tmp = tmp->next);
	return (count);
}
