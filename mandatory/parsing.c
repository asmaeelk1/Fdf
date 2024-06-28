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
	if(fd < 0)
        fatal(INVALID_FILE);
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
static void line_parcer(char *axis,t_data **data, t_x *x, int y)
{
    char	**points;
	// char	*color;
    int		i;
	int		altitude;

    i = 0;
	altitude  = 0;
    points = ft_split(axis, ' ');
    while(points[i])
    {
		altitude = ft_atoi(ft_strtok(points[i], ','),&x);
        ft_lstadd_back_axis(&x, ft_lstnew_axis(altitude,i ,y));
		// color = ft_strtok(NULL, ',');
		// if(*color != '\0')
		// 	x->color = putnbr_hex(color);
		// else
		// 	x->color = putnbr_hex("0xFFFFFF");
        i++;
    }
	ft_lstadd_back_map(data, x);
}

void parsing(char *file_name, t_data **data)
{
    int     file;
	int		width;
	int		height;
    char    *axis;
	t_x		*line = NULL;

    file = check_file(file_name);
    axis = get_next_line(file);
	if(!axis)
		fatal(EMPTY_FILE);
	width = line_len(axis);
	height = 0;
    while(axis)
    {
		if(!ft_strncmp(axis, "\n", ft_strlen(axis)) )
		{
			axis = get_next_line(file);
	 		continue;
		}
        if(width != line_len(axis))
            fatal(INVALID_MAP);
        line_parcer(axis, data,line, height);
		height++;
        axis = get_next_line(file);
    }
	(*data)->width = width;
	(*data)->height = height;
	(*data)->altitude_inc = 1;
	((WIDTH <= HEIGHT) && ((*data)->map->space = (WIDTH / 2) / (*data)->width) ) ||
		((*data)->map->space = (HEIGHT / 2) / (*data)->width);
	
}
