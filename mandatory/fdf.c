/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 10:19:15 by asel-kha          #+#    #+#             */
/*   Updated: 2024/07/08 16:20:38 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// void	ft_hook(void *param)
// {
// 	t_data	*data;

// 	data = param;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
// 		mlx_close_window(data->mlx);
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_UP))
// 		data->image->instances[0].y -= 5;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
// 		data->image->instances[0].y += 5;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
// 		data->image->instances[0].x -= 5;
// 	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
// 		data->image->instances[0].x += 5;
// }

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (ac != 2)
		fatal(BAD_ARG);
	if (!(data->mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true)))
	{
		ft_putstr_fd(mlx_strerror(mlx_errno), 2);
		return (EXIT_FAILURE);
	}
	if (!(data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT)))
	{
		mlx_close_window(data->mlx);
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(data->mlx, data->image, 0, 0) == -1)
	{
		mlx_close_window(data->mlx);
		return (EXIT_FAILURE);
	}
	parsing(av[1], &data);
	draw_map(&data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
}
