#include "../includes/fdf.h"
#include <stdlib.h>

void isometric_projection(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599);
    *y =  + (previous_x + previous_y) * sin(0.523599) - z;
}
// void	update_points_iso(t_p **p0, t_p **p1,t_p **p2, t_data **data)
// {
	
// }

void plotLine(mlx_image_t *image, int x0, int y0, int x1, int y1) 
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx;
	int	sy;
	int err;

    ((x0 < x1) && ( sx = 1)) || (sx = -1);
	((y0 < y1) && ( sy = 1)) || (sy = -1);
	((dx > dy) && (err = dx / 2)) || ( err = -dy / 2);
    while (1) {
        mlx_put_pixel(image, x0, y0, 0xFFFFFFFF);
        if (x0 == x1 && y0 == y1) break;
        if (err > -dx) { err -= dy; x0 += sx; }
        if (err < dy) { err += dx; y0 += sy; }
    }
}


void	display_center(t_p **p, t_data **data)
{
	(*p)->x *= (*data)->map->space + (*data)->zoom;
	(*p)->y	*= (*data)->map->space + (*data)->zoom;
	(*p)->x -= (((*data)->map->space + (*data)->zoom) * (*data)->width) / 2;
	(*p)->y -= (((*data)->map->space + (*data)->zoom) * (*data)->height) / 2;
	(*p)->x += WIDTH / 2;
	(*p)->y += HEIGHT / 2;

}
void	update_points(t_p **p0, t_p **p1,t_p **p2, t_data **data)
{
	display_center(p0, data);
	display_center(p1, data);
	display_center(p2, data);
}
void draw_map(mlx_image_t *image, t_data **data)
{
    t_map *current_line;
    t_x *points;
    t_p *p0;
    t_p *p1;
    t_p *p2;
	
	(p0 = ft_calloc(1, sizeof(t_p)), p1 =ft_calloc(1, sizeof(t_p)),
		p2 =ft_calloc(1, sizeof(t_p)), current_line = (*data)->map);
    while (current_line)
    {
        points = current_line->lines;
        while (points)
        {
			p0->x = points->x;
			p0->y = points->y;
			p1->x = p0->x +1;
			p1->y = p0->y;
			p2->x =	p0->x;
			p2->y = p0->y + 1;
			update_points(&p0, &p1, &p2, data);

			if (points->next)
				plotLine(image, p0->x, p0->y, p1->x, p0->y);
			if (current_line->next)
				plotLine(image, p0->x, p0->y, p0->x, p2->y);
            points = points->next;
        }
        current_line = current_line->next;
    }
	free(p0);
	free(p1);
	free(p2);
}
