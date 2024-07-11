/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:30:18 by asel-kha          #+#    #+#             */
/*   Updated: 2024/07/11 02:13:26 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	free_struct_lines(t_x **x)
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

void	free_map(t_map **map)
{
	t_map *ptr;
	t_map *tmp;
	
	tmp = *map;
	while(tmp)
	{
		ptr = tmp;
		tmp = tmp->next;
		if(tmp)
			free_struct_lines(&tmp->lines);
		free(ptr);
	}
}
