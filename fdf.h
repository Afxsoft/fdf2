/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:35:30 by aouloube          #+#    #+#             */
/*   Updated: 2016/02/11 18:12:55 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int			max_value;
	t_point2d	offset;
}				t_map;


typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	t_map		map;
}				t_fdf;

int				get_next_line(int fd, char **line);
int				***load_map(char *file);
int				keyboard_event(int keycode);
void			point(t_fdf *fdf, int x, int y, int color);
void			draw_map(t_fdf *fdf);
void			draw_line(t_fdf *fdf, t_point2d start, t_point2d end,
				int color);

#endif
