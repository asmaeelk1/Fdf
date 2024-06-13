#include "../includes/fdf.h"


void	draw_line(mlx_image_t *image , t_p p0, t_p p1, int color)
{
	int dx;
	int dy;
	int increment;
	int diff;
	int D;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	(1) && (dx = p1.x - p0.x, dy = p1.y - p0.y, increment= 1);
	D = (dx + dy);
	while(p0.x != p1.x && p0.y != p1.y)
	{
		diff = 2 * (dy - dx);
		if (diff <= dy)
		{
			(dx < 0) && (increment = -1, 0);
			D -=  dy;
			p0.x = p0.x + increment; 
		}
		if (diff <= dx)
		{
			(dy < 0) && (increment = -1, 0);
			D = D + dx;
			p0.y = p0.y + increment; 
		}
		mlx_put_pixel(image, p0.x, p0.y, color);
	}
}
void	find_points(t_map *map, t_p *start, t_p *end)
{
	int space ;
	if(WIDTH > HEIGHT)
		space = (WIDTH / 2) / ft_lstsize_axis(&map->lines);
	else
		space = (HEIGHT / 2) / ft_lstsize_axis(&map->lines);
	end->x = start->x + space;
	end->x = start->y + space;
}

void	draw_horizental_line(mlx_image_t *image ,t_p start, t_p end,int color)
{
	end.y = start.y;
	draw_line(image, start, end, color);
}

void	draw_vertical_line(mlx_image_t *image ,t_p start, t_p end,int color)
{
	end.x = start.x;
	draw_line(image, start, end, color);
}


void	draw_map(mlx_image_t *image ,t_map **map, int color)
{
	t_map *current_line;
	t_p start;
	t_p end;
	current_line = *map;
	start.x = 50;
	start.y = 50;

	int space ;
	if(WIDTH > HEIGHT)
		space = (WIDTH / 2) / ft_lstsize_axis(&((*map)->lines));
	else
		space = (HEIGHT / 2) / ft_lstsize_map(map);
	while(current_line)
	{
		while(current_line->lines->next)
		{
				
			end.x = start.x + space;
			end.x = start.y + space;
			// find_points(*map, &start, &end);
			draw_horizental_line(image, start, end, color);
			draw_vertical_line(image, start, end, color);
			start.x = start.x + space;
			start.y = start.y + space;
		current_line->lines = current_line->lines->next;
		}
	current_line = current_line->next;
	}
}