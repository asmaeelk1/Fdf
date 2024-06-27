
#include "../includes/fdf.h"
void plotLine(mlx_image_t *image, t_p *p0, t_p *p1, int color)
{
    int dx = abs(p1->x - p0->x);
    int dy = abs(p1->y - p0->y);
    int sx;
	int	sy;
	int err;

    ((p0->x < p1->x) && ( sx = 1)) || (sx = -1);
	((p0->y < p1->y) && ( sy = 1)) || (sy = -1);
	((dx > dy) && (err = dx / 2)) || ( err = -dy / 2);
    while (1) {
        if (p0->x == p1->x && p0->y == p1->y) break;
        if ((2 *err) > -dx) 
		{ 
			err -= dy;
			p0->x += sx;
		}
        else if ((2 * err) < dy)
		{
			err += dx;
			p0->y += sy;
		}
        mlx_put_pixel(image, p0->x, p0->y, color);
    }
}

void	update_points_iso(t_p **p)
{


 	int previous_x;
    int previous_y;
	int z = (*p)->altitude;

    previous_x = (*p)->x;
    previous_y = (*p)->y;
   (*p)->x = (previous_x - previous_y) * cos(0.523599);
   (*p)->y= -z + (previous_x + previous_y) * sin(0.523599);

	// t_p *var_rot_x;
	// t_p *var_rot_y;
	// t_p *var_rot_z;

	// var_rot_x = *p;
	// var_rot_x->x = var_rot_x->x;
	// var_rot_x->y =  var_rot_x->y * cos(0.523599) - (var_rot_x->altitude * sin(0.523599));
	// var_rot_x->altitude =  (var_rot_x->y * sin(0.523599)) + (var_rot_x->altitude *  cos(0.523599));
	// var_rot_y = var_rot_x;
	// var_rot_y->x = (var_rot_x->x * cos(0.523599)) + (var_rot_x->altitude * sin(0.523599));
	// var_rot_y->y = var_rot_y->y;
	// var_rot_y->altitude = (var_rot_x->x * -sin(0.523599)) + (var_rot_x->altitude * cos(0.523599));
	// var_rot_z = var_rot_y;
	// var_rot_z->x = ( var_rot_y->x * cos(0.523599)) + (var_rot_y->altitude * -sin(0.523599));
	// var_rot_z->y = ( var_rot_y->x * sin(0.523599)) + (var_rot_y->y *  cos(0.523599));
	// var_rot_z->altitude = var_rot_y->altitude;
	// *p = var_rot_z;
}


void	display_center(t_p **p, t_data **data)
{
	(*p)->x *= (*data)->map->space + (*data)->zoom;
	(*p)->y	*= (*data)->map->space + (*data)->zoom;
	(*p)->x -= (((*data)->map->space + (*data)->zoom) * (*data)->width) / 2;
	(*p)->y -= (((*data)->map->space + (*data)->zoom) * (*data)->height) / 2;
	// update_points_iso(p);
	(*p)->x += WIDTH / 2;
	(*p)->y += HEIGHT / 2;
}
void	update_points(t_p **p0, t_p **p1,t_p **p2, t_data **data)
{
	display_center(p0, data);
	display_center(p1, data);
	display_center(p2, data);
}
// void draw_map(mlx_image_t *image, t_data **data)
// {
//     t_map *current_line;
//     t_x *points, *next_point;
//     t_p *p0, *p1, *p2;

    
//     p0 = ft_calloc(1, sizeof(t_p));
//     p1 = ft_calloc(1, sizeof(t_p));
//     p2 = ft_calloc(1, sizeof(t_p));
//     current_line = (*data)->map;

    
//     while (current_line)
//     {
//         points = current_line->lines;
        
//         while (points)
//         {
//             p0->x = points->x;
//             p0->y = points->y;
//             p0->altitude = points->altitude;
//             if (points->next)
//             {
//                 p1->x = points->next->x;
//                 p1->y = points->next->y;
//                 p1->altitude = points->next->altitude;
//             }
//             else
//             {
//                 p1->x = points->x + 1;
//                 p1->y = points->y;
//                 p1->altitude = points->altitude;
//             }
            
//             if (current_line->next)
//             {
//                 next_point = current_line->next->lines;
//                 while (next_point && next_point->x < points->x)
//                 {
//                     next_point = next_point->next;
//                 }
//                 if (next_point)
//                 {
//                     p2->x = next_point->x;
//                     p2->y = next_point->y;
//                     p2->altitude = next_point->altitude;
//                 }
//                 else
//                 {
//                     p2->x = points->x;
//                     p2->y = points->y + 1;
//                     p2->altitude = points->altitude;
//                 }
//             }
//             else
//             {
//                 p2->x = points->x;
//                 p2->y = points->y + 1;
//                 p2->altitude = points->altitude;
//             }
            
//             update_points(&p0, &p1, &p2, data);
//             if (points->next)
//             	plotLine(image, p0, p1, points->color);
// 			if (current_line->next)
//             	plotLine(image, p0, p2, points->color);
            
//             points = points->next;
//         }
        
//         current_line = current_line->next;
//     }
    
//     free(p0);
//     free(p1);
//     free(p2);
// }

void draw_map(mlx_image_t *image, t_data **data)
{
    t_map *current_line;
    t_x *points, *next_point;
    current_line = (*data)->map;

    
    while (current_line)
    {
        points = current_line->lines;
        
        while (points)
        {
           
        }
        
        current_line = current_line->next;
    }
    
}