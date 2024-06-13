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


#define WIDTH 1000
#define HEIGHT 1000

# define BAD_ARG "\033[31mError:\033[0m Bad arguments\n"
# define INVALID_FILE "\033[31mError:\033[0m Invalide file\n"
# define INVALID_MAP "\033[31mError:\033[0m Invalide map\n"
# define EMPTY_FILE "\033[31mError:\033[0m Empty file\n"
# define MALLOC_FAIL "\033[31mAllocation fail\033[0m\n"

typedef struct s_x  t_x;
typedef struct s_map  t_map;
typedef struct s_data  t_data;
typedef struct s_p  t_p;


struct s_x
{
    int altitude;
	int axis;
	int ordinate;
    int color;
    t_x *next;
};

struct s_map
{
    t_x *lines;
   t_map *next;
};

struct s_data
{
    t_x		*axis;
    t_map	*ordinat;
	int		x;
	int		y;

};

struct	s_p
{
	int	x;
	int y;
	int color;
};

char	*get_next_line(int fd);
void	fatal(const char *msg);
void parsing(char *file_name, t_map **map);
int		ft_putnbr_hex(unsigned long c, char start);
char	**ft_split(char *s, char c);
char	*ft_strdup(const char *s1);
int		ft_strncmp(char *s1, char *s2, size_t n);
size_t	ft_strlen(const char *c);
int		ft_atoi(const char *str, t_x **x);
t_x		*ft_lstnew_axis(int altitude);
t_x		*ft_lstlast_axis(t_x *x);
void	ft_lstadd_back_axis(t_x **x, t_x *new);
int		ft_lstsize_axis(t_x **x);
t_map	*ft_lstnew_map(t_x *axis);
t_map	*ft_lstlast_map(t_map **map);
void	ft_lstadd_back_map(t_map **map, t_x *new);
int	ft_lstsize_map(t_map **map);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_putstr_fd(const char *s, int fd);
void	free_struct(t_x **x);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char *ft_strtok(char *str, char del);
// void	plotLine(t_p0 p0, t_p1 p1, t_data data, mlx_image_t **image);
void	draw_line(mlx_image_t *image , t_p p0, t_p p1, int color);
// void	draw_line(int x0, int y0, int x1, int y1);
void	draw_map(mlx_image_t *image ,t_map **map, int color);


# endif
