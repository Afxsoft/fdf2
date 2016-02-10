#include "fdf.h"

int keyboard_event(int keycode)
{
	if (keycode == KEYCODE_ESC)
		exit(0);
	return (0);
}

void	draw_point(t_fdf *fdf, int x, int y, int color)
{
	mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
}

void	draw_line(t_fdf *fdf, t_point2d start, t_point2d end, int color)
{
	t_point2d	delta;
	t_point2d	inc;
	int			e;
	int			ee;

	delta.x = abs(end.x - start.x);
	delta.y = abs(end.y - start.y);
	inc.x = (start.x < end.x) ? 1 : -1;
	inc.y = (start.y < end.y) ? 1 : -1;
	e = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	while (start.x != end.x || start.y != end.y)
	{
		draw_point(fdf, start.x, start.y, color);
		ee = e;
		if (ee > -delta.x && (start.x += inc.x))
			e -= delta.y;
		if (ee < delta.y && (start.y += inc.y))
			e += delta.x;
	}
}
