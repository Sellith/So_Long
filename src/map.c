/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:06:36 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/04 23:36:22 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/So_Long.h"

static bool	double_map_check(int fd)
{
	char	*buffer;

	buffer = get_next_line(fd);
	while (buffer)
	{
		if (buffer[0] != '\n' && buffer)
			return (ft_printf("Error: Parsing error\n"),
				free(buffer), get_next_line(-1), false);
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	return (true);
}

static bool	flood_fill(t_game *data, int x, int y)
{
	if (data->pars->ffmap[x][y] == '1' || data->pars->ffmap[x][y] == '-'
		|| data->pars->ffmap[x][y] == 'i' || data->pars->ffmap[x][y] == 'e'
		|| data->pars->ffmap[x][y] == 'X')
		return (false);
	if (data->pars->ffmap[x][y] == 'C')
	{
		data->pars->ffmap[x][y] = 'i';
		data->map->reachable++;
	}
	if (data->pars->ffmap[x][y] == '0')
		data->pars->ffmap[x][y] = '-';
	if (data->pars->ffmap[x][y] == 'E')
	{
		data->pars->ffmap[x][y] = 'e';
		data->pars->exit = true;
	}
	flood_fill(data, x, y + 1);
	flood_fill(data, x + 1, y);
	flood_fill(data, x, y - 1);
	flood_fill(data, x - 1, y);
	if (!data->pars->exit || data->map->reachable != data->map->marker[2])
		return (false);
	return (true);
}

static bool	map_check(t_game *data, int x, int y)
{
	while (data->map->map[x][y])
		if (data->map->map[x][y++] != '1')
			return (false);
	data->map->size_line = y;
	x = intermap_check(data->map, y, 0, 0);
	if (x == -1 || (int)ft_strlen(data->map->map[x]) != y)
		return (false);
	while (y > 0)
		if (data->map->map[x][--y] != '1')
			return (false);
	data->map->size_col = x + 1;
	data->pars = malloc(sizeof(t_pars));
	if (!data->pars)
		return (false);
	data->pars->ffmap = ft_arraydup(data->map->map);
	if (!data->pars->ffmap)
		return (free(data->pars), false);
	data->pars->exit = false;
	if (!flood_fill(data, data->map->spawn[1], data->map->spawn[0]))
		return (freedarray(data->pars->ffmap), free(data->pars), false);
	return (freedarray(data->pars->ffmap), free(data->pars), true);
}

static bool	map_opening(t_map *data, char *mappath)
{
	char	*buff;
	char	*map;

	data->mapfd = open(mappath, O_RDONLY);
	if (data->mapfd == -1)
		return (ft_printf("Error: File access\n"), false);
	buff = get_next_line(data->mapfd);
	if (!buff)
		return (ft_printf("Error: Empty file\n"), false);
	map = ft_strdup("");
	if (!map)
		return (ft_printf("Error: Malloc error\n"), free(buff), false);
	while (buff && buff[0] != '\n')
	{
		map = ft_strjoining(map, buff);
		free(buff);
		buff = get_next_line(data->mapfd);
	}
	if (buff && buff[0] == '\n')
		if (!double_map_check(data->mapfd))
			return (free(buff), free(map), false);
	data->map = ft_split(map, '\n');
	if (!data->map)
		return (ft_printf("Error: Malloc error\n"), free(buff), false);
	return (free(buff), free(map), true);
}

bool	map_parsing(t_game *data, char *mappath)
{
	if (ft_strncmp(mappath + (ft_strlen(mappath) - 4), ".ber", 4))
		return (false);
	data->map = malloc(sizeof(t_map));
	if (!data->map)
		return (false);
	data->map->map = NULL;
	data->map->marker[0] = 0;
	data->map->marker[1] = 0;
	data->map->marker[2] = 0;
	data->map->reachable = 0;
	if (!map_opening(data->map, mappath))
		return (exit_w_code(1, data), false);
	if (!map_check(data, 0, 0))
		return (ft_printf("Error: Map check \n"), exit_w_code(1, data), false);
	return (true);
}
