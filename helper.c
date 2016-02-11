/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:04:12 by aouloube          #+#    #+#             */
/*   Updated: 2016/02/11 18:47:46 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int keyboard_event(int keycode)
{
	if (keycode == KEYCODE_ESC)
		exit(0);
	return (0);
}

void	draw_line(t_fdf *fdf, t_point2d start, t_point2d end, int color)
{
	t_point2d	delta;
	t_point2d	inc;
	int			res;
	int			keep_res;

	delta.x = abs(end.x - start.x);
	delta.y = abs(end.y - start.y);
	inc.x = (start.x < end.x) ? 1 : -1;
	inc.y = (start.y < end.y) ? 1 : -1;
	res = (delta.x > delta.y ? delta.x : -delta.y) / 2;
	while (start.x != end.x || start.y != end.y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, start.x, start.y, color);
		keep_res = res;
		if (keep_res > -delta.x && (start.x += inc.x))
			res -= delta.y;
		if (keep_res < delta.y && (start.y += inc.y))
			res += delta.x;
	}
}
