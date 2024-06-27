#include "../includes/fdf.h"

static mlx_image_t* image;

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


int main(int ac, char **av)
{
	t_data *data;
	
	data = ft_calloc(1, sizeof(t_data));
    if (ac != 2)
        fatal(BAD_ARG);
    parsing(av[1], &data);
	if (!(data->mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(data->mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(data->mlx);
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, image, 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		return(EXIT_FAILURE);
	}
	
	draw_map(image, &data);
	mlx_loop_hook(data->mlx, ft_hook, data->mlx);

	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
    return 0;
}

