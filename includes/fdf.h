# ifndef FDF_H
# define FDF_H

# include "../MLX/include/MLX42/MLX42.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

 
#define WIDTH 1800
#define HEIGHT 1200

# define BAD_ARG "\033[31mError:\033[0m Bad arguments\n"
# define INVALID_FILE "\033[31mError:\033[0m Invalide file\n"
# define INVALID_MAP "\033[31mError:\033[0m Invalide map\n"
# define EMPTY_FILE "\033[31mError:\033[0m Empty file\n"
# define MALLOC_FAIL "\033[31mAllocation fail\033[0m\n"

typedef struct s_p  t_p;
typedef struct s_x  t_x;
typedef struct s_map  t_map;
typedef struct s_data  t_data;
typedef struct s_plotline  t_plotline;
struct	s_p
{
	int	x;
	int y;
	int altitude;
	int color;
};
struct s_x
{
	int	x;
	int	y;
    int altitude;
    int color;
    t_x *next;
};

struct s_map
{
    t_x *lines;
	int space;
	t_map *next;
};

struct s_data
{
    t_map	*map;
	int width;
	int height;
	int zoom;
	mlx_t* mlx;
	mlx_image_t* image;
};

struct s_plotline
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
};

char	*get_next_line(int fd);
void	fatal(const char *msg);
int		putnbr_hex(char *hex);
void	parsing(char *file_name, t_data **data);
char	**ft_split(char *s, char c);
char	*ft_strdup(const char *s1);
int		ft_strncmp(char *s1, char *s2, size_t n);
size_t	ft_strlen(const char *c);
int		ft_atoi(const char *str, t_x **x);
t_x		*ft_lstnew_axis(int altitude, int x, int y, char *color);
t_x		*ft_lstlast_axis(t_x *x);
void	ft_lstadd_back_axis(t_x **x, t_x *new);
int		ft_lstsize_axis(t_x **x);
t_map	*ft_lstnew_map(t_x *axis);
t_map	*ft_lstlast_map(t_map **map);
void	ft_lstadd_back_map(t_data **data, t_x *new);
int		ft_lstsize_map(t_map **map);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_putstr_fd(const char *s, int fd);
void	free_struct(t_x **x);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// char	*ft_strtok(char *str, char *sep);

char	*ft_strtok(char *str, char del);
// void	plotLine(mlx_image_t *image, t_p p0, t_p p1, int color);
// void plotLine(mlx_image_t *image, int x0, int y0, int x1, int y1); 
// void	update_points_iso(t_p *p);
void	draw_map(t_data **data);

# endif