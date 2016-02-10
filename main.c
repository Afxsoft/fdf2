#include "fdf.h"

static void		ft_init(t_fdf *fdf, char *file)
{
	int ***temp;

	temp = load_map(file);
	fdf->map.map = temp;
	fdf->map.offset.x = WIN_WIDTH / 2;
	fdf->map.offset.y = WIN_HEIGHT / 8;
	if (!(fdf->mlx = mlx_init()))
		return ;
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF");
}

static void		ft_checks(int argc, char **argv)
{
	int		fd;

	if (argc !=  2)
		exit(0);
	fd = open (argv[1], O_RDONLY);
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
	mlx_expose_hook(fdf.win, draw_map, &fdf);
	mlx_key_hook(fdf.win, keyboard_event, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
