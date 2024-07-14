/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 02:49:58 by asel-kha          #+#    #+#             */
/*   Updated: 2024/07/14 02:50:24 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	plot_line(mlx_image_t *image, t_p p0, t_p p1, int color)
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
