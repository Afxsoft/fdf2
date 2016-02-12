/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:23:45 by aouloube          #+#    #+#             */
/*   Updated: 2016/02/12 16:35:01 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point2d	get_iso_point(t_fdf *fdf, int x, int y, int z)
{
	t_point2d		point;

	point.x = ISO_ANGLE * (x * cos(RAD(ISO_ANGLE)) - y *
			cos(RAD(ISO_ANGLE)));
	point.y = (-ISO_ANGLE) * ((z * fdf->relief) - x *
			sin(RAD(ISO_ANGLE)) - y * sin(RAD(ISO_ANGLE)));
	point.x += fdf->map.offset.x;
	point.y += fdf->map.offset.y;
	return (point);
}

static int			upper_point(int ***map, int x, int y)
{
	int				i;

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

void				draw_map(t_fdf *fdf, int color, int deg)
{
	int		x;
	int		y;

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
			if (deg)
				color++;
		}
		y++;
	}
}
