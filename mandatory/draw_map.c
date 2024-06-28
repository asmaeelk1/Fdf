
#include "../includes/fdf.h"

void plotLine(mlx_image_t *image, t_p p0, t_p p1, int color) {
    int dx = abs(p1.x - p0.x);
    int dy = abs(p1.y - p0.y);
    int sx = (p0.x < p1.x) ? 1 : -1;
    int sy = (p0.y < p1.y) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        if (p0.x >= 0 && p0.y >= 0 && p0.x < WIDTH && p0.y < HEIGHT) 
            mlx_put_pixel(image, p0.x, p0.y, color);
        if (p0.x == p1.x && p0.y == p1.y) break;
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            p0.x += sx;
        }
        if (e2 < dx) {
            err += dx;
            p0.y += sy;
        }
    }
}

void	update_points_iso(t_p *p)
{
 	int previous_x;
    int previous_y;
	int z = (*p).altitude;

    previous_x = (*p).x;
    previous_y = (*p).y;
   (*p).x = (previous_x - previous_y) * cos(0.523599);
   (*p).y=  (previous_x + previous_y) * sin(0.523599) - z;
}

void	display_center(t_p **p, t_data **data)
{
	(*data)->zoom = 1;
	(*p)->x *= (*data)->map->space + (*data)->zoom;
	(*p)->y	*= (*data)->map->space + (*data)->zoom;
	if((*p)->altitude > 0)
		(*p)->altitude *= (*data)->altitude_inc;
	(*p)->x -= (((*data)->map->space + (*data)->zoom) * (*data)->width) / 2;
	(*p)->y -= (((*data)->map->space + (*data)->zoom) * (*data)->height) / 2;
	update_points_iso(*p);
	(*p)->x += WIDTH / 2;
	(*p)->y += HEIGHT / 2;
}

void draw_map(mlx_image_t *image, t_data **data) {
    t_map *current_line = (*data)->map;
    t_p *p1 = ft_calloc(1, sizeof(t_p));
    t_p *p2 = ft_calloc(1, sizeof(t_p));
	t_x *tmp ;

    while (current_line)
    {
		(current_line->next) && (tmp = current_line->next->lines);
        while (current_line->lines)
        {
           p1 = &((t_p){current_line->lines->x, current_line->lines->y,
			current_line->lines->altitude, current_line->lines->color});
		   p2 = &(t_p){p1->x + 1, p1->y, current_line->lines->altitude, p1->color};
		   if(current_line->lines->next)
				p2->altitude = current_line->lines->next->altitude;
		   display_center(&p1, data);
		   display_center(&p2, data);
		   if (current_line->lines->next)
                plotLine(image, *p1, *p2, current_line->lines->color);
			if (tmp)
            {
                p1 = &((t_p){current_line->lines->x, current_line->lines->y,
					current_line->lines->altitude, current_line->lines->color});
                p2 = &(t_p){p1->x , p1->y + 1, tmp->altitude, p1->color};
                display_center(&p1, data);
                display_center(&p2, data);
                plotLine(image, *p1, *p2,  current_line->lines->color);
                tmp = tmp->next;
            }
            current_line->lines = current_line->lines->next;
        }
        current_line = current_line->next;
    }
}

