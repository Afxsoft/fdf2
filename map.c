/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aouloube <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 14:32:03 by aouloube          #+#    #+#             */
/*   Updated: 2016/02/11 18:01:51 by aouloube         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*malloc_int(int p)
{
	int		*i;

	if (!(i = (int*)malloc(sizeof(int))))
		exit(0);
	*i = p;
	return (i);
}

static int	**tab_atoi(char **tab_char)
{
	int		**tab_int;
	size_t	i;
	size_t	j;

	i = 0;
	while (tab_char[i])
		i++;
	if (!(tab_int = (int**)malloc(sizeof(int*) * (i + 1))))
		exit(0);
	j = 0;
	while (tab_char[j])
	{
		tab_int[j] = malloc_int(ft_atoi(tab_char[j]));
		j++;
	}
	tab_int[j] = NULL;
	return (tab_int);
}

static int		ft_count_l(char *file)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

int			***load_map(char *file)
{
	int		***map;
	char	*line;
	char	**l2;
	int		fd;
	size_t	i;

	if (!(map = (int***)malloc(sizeof(int**) * (ft_count_l(file) + 1))))
		exit(0);
	fd = open(file, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		l2 = ft_strsplit(line, ' ');
		map[i] = tab_atoi(l2);
		free(l2);
		free(line);
		i++;
	}
	close(fd);
	map[i] = NULL;
	return (map);
}
