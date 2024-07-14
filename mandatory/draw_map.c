/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:01:02 by asel-kha          #+#    #+#             */
/*   Updated: 2024/07/15 00:32:42 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	update_points_iso(t_p *p)
{
	int	previous_x;
	int	previous_y;
	int	z;

	z = p->altitude;
	previous_x = p->x;
	previous_y = p->y;
	p->x = (previous_x - previous_y) * cos(0.523599);
	p->y = (previous_x + previous_y) * sin(0.523599) - z;
}

static void	display_center(t_p *p, t_data **data)
{
	(*data)->zoom = 1;
	p->x *= (*data)->map->space + (*data)->zoom;
	p->y *= (*data)->map->space + (*data)->zoom;
	p->x -= (((*data)->map->space + (*data)->zoom) * (*data)->width) / 2;
	p->y -= (((*data)->map->space + (*data)->zoom) * (*data)->height) / 2;
	update_points_iso(p);
	p->x += WIDTH / 2;
	p->y += HEIGHT / 2;
}

static void	draw_horizontal_line(t_data **data, t_p *p1, t_p *p2, t_map **line)
{
	*p1 = (t_p){(*line)->lines->x, (*line)->lines->y,
		(*line)->lines->altitude, (*line)->lines->color};
	*p2 = (t_p){p1->x + 1, p1->y, (*line)->lines->altitude,
		p1->color};
	if ((*line)->lines->next)
		p2->altitude = (*line)->lines->next->altitude;
	(1) && (display_center(p1, data), display_center(p2, data), 0);
	if ((*line)->lines->next)
		plot_line(((*data)->image), *p1, *p2,
			(*line)->lines->color);
}

static void	draw_vertical_line(t_data **data, t_draw_map *var_draw_map)
{
	*(*var_draw_map).p1 = ((t_p){(*var_draw_map).map->lines->x,
			(*var_draw_map).map->lines->y, (*var_draw_map).map->lines->altitude,
			(*var_draw_map).map->lines->color});
	*(*var_draw_map).p2 = (t_p){(*var_draw_map).p1->x,
		(*var_draw_map).p1->y + 1, (*var_draw_map).tmp->altitude,
		(*var_draw_map).p1->color};
	display_center((*var_draw_map).p1, data);
	display_center((*var_draw_map).p2, data);
	plot_line(((*data)->image), *(*var_draw_map).p1, *(*var_draw_map).p2,
		(*var_draw_map).map->lines->color);
	(*var_draw_map).tmp = (*var_draw_map).tmp->next;
}

void	draw_map(t_data **data)
{
	t_draw_map	var;
	t_x			*lines;

	var.tmp = NULL;
	(1) && (var.map = (*data)->map);
	var.p1 = ft_calloc(1, sizeof(t_p));
	var.p2 = ft_calloc(1, sizeof(t_p));
	while (var.map)
	{
		(var.map->next) && (var.tmp = var.map->next->lines);
		while (var.map->lines)
		{
			lines = var.map->lines;
			draw_horizontal_line(data, var.p1, var.p2, &var.map);
			if (var.tmp)
				draw_vertical_line(data, &var);
			var.map->lines = var.map->lines->next;
			free(lines);
		}
		var.map = var.map->next;
	}
	free(var.p1);
	free(var.p2);
}
