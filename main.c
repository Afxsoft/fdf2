/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:03:50 by aouloube          #+#    #+#             */
/*   Updated: 2016/02/12 16:39:04 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_init(t_fdf *fdf, char *file)
{
	int			***temp;

	temp = load_map(file);
	fdf->map.map = temp;
	fdf->map.offset.x = WIN_WIDTH / 2;
	fdf->map.offset.y = WIN_HEIGHT / 8;
	fdf->relief = 0.1;
	if (!(fdf->mlx = mlx_init()))
		return ;
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
}

int				expose_hook(t_fdf *fdf)
{
	draw_map(fdf, 0x00BA3733, 1);
	return (0);
}

static void		ft_checks(int argc, char **argv)
{
	int		fd;

	if (argc != 2)
		exit(0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	else
		close(fd);
}

int				main(int argc, char **argv)
{
	t_fdf		fdf;

	ft_checks(argc, argv);
	ft_init(&fdf, argv[1]);
	mlx_key_hook(fdf.win, keyboard_event, &fdf);
	mlx_expose_hook(fdf.win, expose_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
