#include "../includes/fdf.h"


int main(int ac, char **av)
{
	t_x *axis;
	t_map *map;

	(1) && (axis = NULL, map = NULL);
    if (ac != 2)
        fatal(BAD_ARG);
    parsing(av[1]);

	// char* first_line = skip_map_header()
	// char **map_body = get_map_body()
	// skip_map_footer()

    return 0;
}