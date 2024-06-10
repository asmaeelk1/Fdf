#include "../includes/fdf.h"


// typedef struct s_varPlotLine t_varPlotLine;

// struct s_varPlotLine
// {
// 	int dx;
// 	int dy;
// 	int increment_x;
// 	int increment_y;
// 	int pose_pixel;
// 	int pose_pixel2;
// };

// void init_var(t_varPlotLine *var, t_p0 p0, t_p1 p1)
// {
// 	var->dx = abs(p1.x1 - p0.x0);
// 	var->dy = abs(p1.y1 - p0.y0);
// 	((p0.x0 < p1.x1) && (var->increment_x = 1)) || (var->increment_x = -1);
// 	((p0.y0 < p1.y1) && (var->increment_y = 1)) || (var->increment_y = -1);
// 	var->pose_pixel = var->dx + var->dy;
// 	var->pose_pixel2 = 2 * var->pose_pixel;

// }

// void	plotLine(t_p0 p0, t_p1 p1, t_data data, mlx_image_t **image)
// {
// 	t_varPlotLine var;
// 	init_var(&var , p0, p1);
// 	while(true)
// 	{
// 		puts("hjh");
// 			mlx_put_pixel(*image, data.x, data.y, 0xFFFFFF);
// 		if((p0.x0 == p1.x1) && (p0.y0 == p1.y1)) break;
// 		if(var.pose_pixel2 >= var.dy)
// 		{
// 			if(p0.x0 == p1.x1) break;
// 			var.pose_pixel += var.dy; 
// 			data.x = p0.x0 + var.increment_x;
// 		}
// 		if(var.pose_pixel2 <= var.dx)
// 		{
// 			if(p0.y0 == p1.y1) break;
// 			var.pose_pixel += var.dx;
// 			data.y = p0.y0 + var.increment_y;
// 		}
// 	}
// }

void	ft_lowline(mlx_image_t *image , t_p p0, t_p p1, int color)
{
	int	d;
	int	inc;
	int	dy;
	int	dx;

	inc = 1;
	dy = p1.y - p0.y;
	dx = p1.x - p0.x;
	(dy < 0) && (inc = -1, dy = -dy, 0);
	d = 2 * (dy - dx);
	while (p0.x <= p1.x)
	{
		if (d > 0)
		{
			p0.y = p0.y + inc;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + (2 * dy);
		if ((p0.x >= 0 && p0.y >= 0) && (p0.x < WIDTH && p0.y < HEIGHT))
			mlx_put_pixel(image, p0.x, p0.y, color);
		p0.x++;
	}
}

void	ft_heightline(mlx_image_t *image , t_p p0, t_p p1, int color)
{
	int	d;
	int	inc;
	int	dy;
	int	dx;

	inc = 1;
	dy = p1.y - p0.y;
	dx = p1.x - p0.x;
	(dx < 0) && (inc = -1, dx = -dx, 0);
	d = 2 * (dx - dy);
	while (p0.y <= p1.y)
	{
		if (d > 0)
		{
			p0.x = p0.x + inc;
			d = d + (2 * (dx - dy));
		}
		else
			d = d + (2 * dx);
		if ((p0.x >= 0 && p0.y >= 0) && (p0.x < WIDTH && p0.y < HEIGHT))
			mlx_put_pixel(image, p0.x, p0.y, color);
		p0.y++;
	}
}

void	draw_line(mlx_image_t *image , t_p p0, t_p p1, int color)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			ft_lowline(image, p1, p0, color);
		else
			ft_lowline(image, p0, p1, color);
	}
	else
	{
		if (p0.y > p1.y)
			ft_heightline(image, p1, p0, color);
		else
			ft_heightline(image, p0, p1, color);
	}
}