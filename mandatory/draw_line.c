#include "../includes/fdf.h"

void draw_line(mlx_image_t *image, t_p p0, t_p p1, int color) {
    int dx = abs(p1.x - p0.x);
    int dy = abs(p1.y - p0.y);

    int increment_x = (p1.x > p0.x) ? 1 : -1;
    int increment_y = (p1.y > p0.y) ? 1 : -1;

    int diff = 0;
    int D = 0;

    int x = p0.x;
    int y = p0.y;

    if (dx >= dy) {
        D = dx;
        diff = dy - dx / 2;
        while (x != p1.x) {
            mlx_put_pixel(image, x, y, color);
            x += increment_x;
            if ((diff += dy) >= 0) {
                y += increment_y;
                diff -= dx;
            }
        }
    } else {
        D = dy;
        diff = dx - dy / 2;
        while (y != p1.y) {
            mlx_put_pixel(image, x, y, color);
            y += increment_y;
            if ((diff += dx) >= 0) {
                x += increment_x;
                diff -= dy;
            }
        }
    }
    mlx_put_pixel(image, p1.x, p1.y, color);
}


void	draw_horizontal_line(mlx_image_t *image ,t_p start, t_p end,int color)
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
	end.x = 0;
	end.y = 0;
	int space ;
	((WIDTH > HEIGHT) && (space = (WIDTH / 2) / ft_lstsize_axis(&((*map)->lines))) )
		|| (space = (HEIGHT / 2) / ft_lstsize_map(map));
	while (current_line)
	{
        while (current_line->lines) {
            end.x = start.x + space;
            end.y = start.y; 
            draw_horizontal_line(image, start, end, color);
            end.x = start.x;
            end.y = start.y + space; 
            draw_vertical_line(image, start, end, color);
            start.x = start.x + space;
            current_line->lines = current_line->lines->next;
        }
		draw_vertical_line(image, start, end, color);
        start.x = 50;
        start.y = start.y + space; 
		end.x = end.x + space;
    	end.y = end.y;
        draw_horizontal_line(image, start, end, color);
        current_line = current_line->next; 
    }
}
