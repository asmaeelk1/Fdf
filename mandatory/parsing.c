/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:55:30 by asel-kha          #+#    #+#             */
/*   Updated: 2024/07/14 00:47:06 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

int	check_file(char *file)
{
	int	i;
	int	fd;

	i = 0;
	fd = -1;
	while (file[i])
		i++;
	i--;
	while (file[i] != '.')
		i--;
	if (!ft_strncmp(file + i, ".fdf", ft_strlen(file + i)))
		fd = open (file, O_RDONLY, 0644);
	if (fd < 0)
		fatal(INVALID_FILE);
	return (fd);
}

static void	line_parcer(char *axis, t_data **data, t_x *x, int y)
{
	char	**points;
	char	*color;
	int		i;
	int		altitude;

	altitude = 0;
	points = ft_split(axis, ' ');
	i = 0;
	while (points[i])
	{
		altitude = ft_atoi(ft_strtok(points[i], ','), &x);
		color = ft_strtok(NULL, ',');
		free (points[i]);
		ft_lstadd_back_axis(&x, ft_lstnew_axis(altitude, i, y, color));
		free(color);
		i++;
	}
	free (points);
	ft_lstadd_back_map(data, x);
}

void	parsing(char *file_name, t_data **data)
{
	int		file;
	int		width;
	int		height;
	char	*axis;
	t_x		*line;

	(1) && (line = NULL, file = check_file(file_name),
		axis = get_next_line(file));
	(!axis) && (free (*data), fatal(EMPTY_FILE), 0);
	(1) && (width = countwords(axis, ' '), height = 0);
	while (axis)
	{
		if (!ft_strncmp(axis, "\n", ft_strlen(axis)))
		{
			(1) && (free (axis), axis = get_next_line(file));
			continue ;
		}
		(width != countwords(axis, ' ')) && (free_map(&(*data)->map),
			free (axis), free(*data), fatal(INVALID_MAP), 0);
		line_parcer(axis, data, line, height);
		(1) && (height++, free (axis), axis = get_next_line(file));
	}
	(1) && (free (axis),(*data)->width = width,  (*data)->height = height);
	((WIDTH <= HEIGHT) && ((*data)->map->space = (WIDTH / 2) / (*data)->width))
		|| ((*data)->map->space = (HEIGHT / 2) / (*data)->width);
}
