/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:53:02 by asel-kha          #+#    #+#             */
/*   Updated: 2024/07/15 00:27:15 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	init_mlx_data(t_data **data)
{
	(*data)->mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true);
	if (!((*data)->mlx))
	{
		ft_putstr_fd(mlx_strerror(mlx_errno), 2);
		return (1);
	}
	(*data)->image = mlx_new_image((*data)->mlx, WIDTH, HEIGHT);
	if (!((*data)->image))
	{
		mlx_close_window((*data)->mlx);
		return (1);
	}
	if (mlx_image_to_window((*data)->mlx, (*data)->image, 0, 0) == -1)
	{
		mlx_close_window((*data)->mlx);
		return (1);
	}
	return (0);
}

void	cleanup_and_exit(t_data *data)
{
	mlx_terminate((*data).mlx);
	free_map(&(*data).map);
	free (data);
	exit (0);
}

void	ft_hook(void *param)
{
	t_data	**data;

	data = param;
	if (mlx_is_key_down((*data)->mlx, MLX_KEY_ESCAPE))
		mlx_close_window((*data)->mlx);
}

void	l(void)
{
	system("leaks fdf");
}

int	main(int ac, char **av)
{
	t_data	*data;
	int		init_mlx;

	atexit(l);
	data = ft_calloc(1, sizeof(t_data));
	if (ac != 2)
		fatal(BAD_ARG);
	parsing(av[1], &data);
	init_mlx = init_mlx_data(&data);
	if (init_mlx)
	{
		free_map(&data->map);
		free (data);
		exit(EXIT_FAILURE);
	}
	draw_map(&data);
	mlx_loop_hook(data->mlx, (void *)ft_hook, &data);
	mlx_loop(data->mlx);
	cleanup_and_exit(data);
}
