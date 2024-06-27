#include "../includes/fdf.h"

// static void	ft_lowline(mlx_image_t *image, t_p *p0, t_p *p1, int color)
// {
// 	int	d;
// 	int	inc;
// 	int	dy;
// 	int	dx;

// 	inc = 1;
// 	dy = p1->y - p0->y;
// 	dx = p1->x - p0->x;
// 	(dy < 0) && (inc = -1, dy = -dy, 0);
// 	d = 2 * (dy - dx);
// 	while (p0->x <= p1->x)
// 	{
// 		if (d > 0)
// 		{
// 			p0->y = p0->y + inc;
// 			d = d + (2 * (dy - dx));
// 		}
// 		else
// 			d = d + (2 * dy);
// 		if ((p0->x >= 0 && p0->y >= 0) && (p0->x < WIDTH && p0->y < HEIGHT))
// 			mlx_put_pixel(image, p0->x, p0->y, color);
// 		p0->x++;
// 	}
// }

// static void	ft_heightline(mlx_image_t *image, t_p *p0, t_p *p1, int color)
// {
// 	int	d;
// 	int	inc;
// 	int	dy;
// 	int	dx;

// 	inc = 1;
// 	dy = p1->y - p0->y;
// 	dx = p1->x - p0->x;
// 	(dx < 0) && (inc = -1, dx = -dx, 0);
// 	d = 2 * (dx - dy);
// 	while (p0->y <= p1->y)
// 	{
// 		if (d > 0)
// 		{
// 			p0->x = p0->x + inc;
// 			d = d + (2 * (dx - dy));
// 		}
// 		else
// 			d = d + (2 * dx);
// 		if ((p0->x >= 0 && p0->y >= 0) && (p0->x < WIDTH && p0->y < HEIGHT))
// 			mlx_put_pixel(image, p0->x, p0->y, color);
// 		p0->y++;
// 	}
// }

// void	plotLine(mlx_image_t *image, t_p *p0, t_p *p1, int color)
// {
// 	if (abs(p1->y - p0->y) < abs(p1->x - p0->x))
// 	{
// 		if (p0->x > p1->x)
// 			ft_lowline(image, p1, p0, color);
// 		else
// 			ft_lowline(image, p0, p1, color);
// 	}
// 	else
// 	{
// 		if (p0->y > p1->y)
// 			ft_heightline(image, p1, p0, color);
// 		else
// 			ft_heightline(image, p0, p1, color);
// 	}
// }


