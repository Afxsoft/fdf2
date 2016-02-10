#include "fdf.h"

static t_point2d	get_iso_point(t_fdf *fdf, int x, int y, int z)
{
	t_point2d	point;

	point.x =  ISO_ANGLE  * (x * cos(RAD(ISO_ANGLE)) - y *
			cos(RAD(ISO_ANGLE)));
	point.y = (-ISO_ANGLE) * ((z * 0.1) - x *
			sin(RAD(ISO_ANGLE)) - y * sin(RAD(ISO_ANGLE)));
	point.x += fdf->map.offset.x;
	point.y += fdf->map.offset.y;
	return (point);
}

static int			upper_point(int ***map, int x, int y)
{
	int		i;

	if (y > 0)
	{
		i = 0;
		while (map[y - 1][i])
			i++;
		if (i > x)
			return (1);
	}
	return (0);
}

static void			buff_image(t_fdf *fdf)
{
	int		x;
	int		y;
	int		color;

	color = 0x00BA3733;
	y = 0;
	while (fdf->map.map[y])
	{
		x = 0;
		while (fdf->map.map[y][x])
		{
			if (fdf->map.map[y][x + 1])
				draw_line(fdf, get_iso_point(fdf, x, y,
							fdf->map.map[y][x][0]), get_iso_point(fdf,
								x + 1, y, fdf->map.map[y][x + 1][0]), color);
			if (upper_point(fdf->map.map, x, y))
				draw_line(fdf, get_iso_point(fdf, x, y,
							fdf->map.map[y][x][0]), get_iso_point(fdf,
								x, y - 1, fdf->map.map[y - 1][x][0]), color);
			x++;
			color++;
		}
		y++;
	}
}

int					draw_map(t_fdf *fdf)
{
	buff_image(fdf);
	return (0);
}
