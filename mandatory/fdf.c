/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asel-kha <asel-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:53:02 by asel-kha          #+#    #+#             */
/*   Updated: 2024/07/12 02:55:09 by asel-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdlib.h>

int	init_mlx_data(t_data **data)
{
	(*data)->mlx = mlx_init(WIDTH, HEIGHT, "Fdf", true);
	if (!((*data)->mlx))
	{
		ft_putstr_fd(mlx_strerror(mlx_errno), 2);
		exit(EXIT_FAILURE);
	}
	(*data)->image = mlx_new_image((*data)->mlx, WIDTH, HEIGHT);
	if (!((*data)->image))
	{
		mlx_close_window((*data)->mlx);
		exit(EXIT_FAILURE);
	}
	if (mlx_image_to_window((*data)->mlx, (*data)->image, 0, 0) == -1)
	{
		mlx_close_window((*data)->mlx);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	l(void)
{
	system("leaks fdf");
}

void free_map2(t_map **map)
{
	// t_map *ptr;
    while(map)
    {
        // ptr = *map;
        free_struct_lines(&(*map)->lines);
        *map = (*map)->next;
    }
    free(*map);
}



int	main(int ac, char **av)
{
	t_data	*data;
	// int		init_mlx;

	atexit(l);
	data = ft_calloc(1, sizeof(t_data));
	if (ac != 2)
		fatal(BAD_ARG);
	parsing(av[1], &data);
	// init_mlx = init_mlx_data(&data);
	// if (init_mlx)
	// {
	// 	free_map(&data->map);
	// 	free(data);
	// 	exit(EXIT_FAILURE);
	// }
	// // draw_map(&data);
    // free_map(&data->map);

    // mlx_loop(data->mlx);
    // mlx_terminate(data->mlx);
    free_map(&data->map);
	// free_map2(&data->map);
    free(data);
    // exit(0);
	exit(0);
	// 0x7ff01540e310
}
