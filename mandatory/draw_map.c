/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 15:01:02 by asel-kha          #+#    #+#             */
/*   Updated: 2024/07/09 15:02:18 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	plot_line(mlx_image_t *image, t_p p0, t_p p1, int color)
{
	t_plotline	vars;

	vars.dx = abs(p1.x - p0.x);
	vars.dy = abs(p1.y - p0.y);
	((p0.x < p1.x) && (vars.sx = 1)) || (vars.sx = -1);
	((p0.y < p1.y) && (vars.sy = 1)) || (vars.sy = -1);
	vars.err = vars.dx - vars.dy;
	while (1)
	{
		if (p0.x >= 0 && p0.y >= 0 && p0.x < WIDTH && p0.y < HEIGHT)
			mlx_put_pixel(image, p0.x, p0.y, color);
		if (p0.x == p1.x && p0.y == p1.y)
			break ;
		vars.e2 = 2 * vars.err;
		if (vars.e2 > -vars.dy)
		{
			vars.err -= vars.dy;
			p0.x += vars.sx;
		}
		if (vars.e2 < vars.dx)
		{
			vars.err += vars.dx;
			p0.y += vars.sy;
		}
	}
}

static void	update_points_iso(t_p *p)
{
	int	previous_x;
	int	previous_y;
	int	z;

	z = (*p).altitude;
	previous_x = (*p).x;
	previous_y = (*p).y;
	(*p).x = (previous_x - previous_y) * cos(0.523599);
	(*p).y = (previous_x + previous_y) * sin(0.523599) - z;
}

static void	display_center(t_p **p, t_data **data)
{
	(*data)->zoom = 1;
	(*p)->x *= (*data)->map->space + (*data)->zoom;
	(*p)->y *= (*data)->map->space + (*data)->zoom;
	(*p)->x -= (((*data)->map->space + (*data)->zoom) * (*data)->width) / 2;
	(*p)->y -= (((*data)->map->space + (*data)->zoom) * (*data)->height) / 2;
	update_points_iso(*p);
	(*p)->x += WIDTH / 2;
	(*p)->y += HEIGHT / 2;
}

static void	draw_line(t_data **data, t_p **p1, t_p **p2, t_map **current_line)
{
	(*p1) = &((t_p){(*current_line)->lines->x, (*current_line)->lines->y,
			(*current_line)->lines->altitude, (*current_line)->lines->color});
	(*p2) = &(t_p){(*p1)->x + 1, (*p1)->y, (*current_line)->lines->altitude,
		(*p1)->color};
	if ((*current_line)->lines->next)
		(*p2)->altitude = (*current_line)->lines->next->altitude;
	(1) && (display_center(p1, data), display_center(p2, data), 0);
	if ((*current_line)->lines->next)
		plot_line(((*data)->image), *(*p1), *(*p2),
			(*current_line)->lines->color);
}

void	draw_map(t_data **data)
{
	t_draw_map	var;

	(1) && (var.map = (*data)->map, var.p1 = ft_calloc(1, sizeof(t_p)),
		var.p2 = ft_calloc(1, sizeof(t_p)));
	while (var.map)
	{
		(var.map->next) && (var.tmp = var.map->next->lines);
		while (var.map->lines)
		{
			draw_line(data, &var.p1, &var.p2, &var.map);
			if (var.tmp)
			{
				var.p1 = &((t_p){var.map->lines->x, var.map->lines->y,
						var.map->lines->altitude, var.map->lines->color});
				var.p2 = &(t_p){var.p1->x, var.p1->y + 1, var.tmp->altitude,
					var.p1->color};
				(display_center(&var.p1, data), display_center(&var.p2, data));
				plot_line(((*data)->image), *var.p1, *var.p2,
					var.map->lines->color);
				var.tmp = var.tmp->next;
			}
			var.map->lines = var.map->lines->next;
		}
		var.map = var.map->next;
	}
}
