#include "../includes/fdf.h"

int check_file(char *file)
{
    int i;
    int fd;

    i = 0;
    fd = -1;
    while(file[i])
        i++;
    i--;
    while(file[i] != '.')
        i--;
    if(!ft_strncmp(file+i, ".fdf", ft_strlen(file+i)))
        fd = open(file, O_RDONLY, 0644);
    return(fd);
}

static int line_len(char *line)
{
    int len;
    char **points;

    points = ft_split(line, ' ');
    len = 0;
    while(points[len])
        len++;
    return(len);
}
static void line_parcer(char *axis,t_map **map, t_x *x)
{
    char	**points;
    int		i;

    i = 0;
    points = ft_split(axis, ' ');
	i = 0;
    while(points[i])
    {
        ft_lstadd_back_axis(&x, ft_lstnew_axis(ft_atoi(ft_strtok(points[i], ','),&x)));
		// x->color = { atoi_hex (ft_strtok(points[i], ',')) }

        i++;
    }
	ft_lstadd_back_map(map, x);
}

void parsing(char *file_name)
{
    int     file;
    int     size_line;
    char    *axis;
	t_map	*map = NULL;
	t_x		*line = NULL;

    file = check_file(file_name);
    if(file < 0)
        fatal(INVALID_FILE);
    axis = get_next_line(file);
	if(!axis)
		fatal(EMPTY_FILE);
    size_line = line_len(axis);
    while(axis)
    {
		if(!ft_strncmp(axis, "\n", ft_strlen(axis)))
		{
			axis = get_next_line(file);
	 		continue;
		}
        if(size_line != line_len(axis))
            fatal(INVALID_MAP);
        line_parcer(axis, &map ,line);
        axis = get_next_line(file);
    }
}
