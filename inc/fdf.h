
#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define RAD(x) (x * M_PI / 180)
# define DEG(x) (x * 180 / M_PI)

# define KEYCODE_ESC 53
# define ISO_ANGLE 30

typedef struct	s_point2d
{
	int			x;
	int			y;
}				t_point2d;

typedef struct	s_map
{
	int			***map;
	t_point2d	offset;
}				t_map;

typedef struct	s_buffer
{
	void		*img;
	char		*data;
	int			bpp;
	int			line_size;
	int			endian;
	int			width;
	int			height;
}				t_buffer;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_buffer	buffer;
}				t_fdf;

int				get_next_line(int fd, char **line);
int				***load_map(char *file);
int				draw_map(t_fdf *fdf);
int				keyboard_event(int keycode);
void			point(t_fdf *fdf, int x, int y, int color);
int				is_in_window(int bounds_width, int bounds_height, int x, int y);
void			draw_line(t_fdf *fdf, t_point2d start, t_point2d end,
				int color);

#endif
