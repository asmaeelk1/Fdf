#include "../includes/fdf.h"


// int main(int ac, char **av)
// {
// 	t_x *axis;
// 	t_map *map;

// 	(1) && (axis = NULL, map = NULL);
//     if (ac != 2)
//         fatal(BAD_ARG);
//     parsing(av[1]);

// 	// char* first_line = skip_map_header()
// 	// char **map_body = get_map_body()
// 	// skip_map_footer()

//     return 0;
// }


// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.

// -----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
# include "../MLX/include/MLX42/MLX42.h"

#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* image;

// -----------------------------------------------------------------------------



void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t main(void)
{
	mlx_t* mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	t_p p0;
	t_p p1;

	p0.x = 50;
	p0.y = 50;
	p1.y = 500;
	p1.x = 500;
	// 	mlx_put_pixel(image, i, i, 0xFFFFFF);
	
	draw_line(image, p0,  p1, 0xFFFFFF);
	// drow_line(point0.x0, point0.y0, point1.x1, point1.y1, &image, data);
	// plotLine( point0, point1, data, &image);
	// mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
