/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:13:18 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/03 16:12:11 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/So_Long.h"

static void	define_spawn(t_map *data, int x, int y)
{
	data->marker[0]++;
	if (data->marker[0] != 1)
		return ;
	data->spawn[0] = x;
	data->spawn[1] = y;
}

static void	define_exit(t_map *data, int x, int y)
{
	data->marker[1]++;
	if (data->marker[1] != 1)
		return ;
	data->exit[0] = x;
	data->exit[1] = y;
}

int	intermap_check(t_map *data, int linelen, int x, int y)
{
	while (data->map[x + 2])
	{
		if ((int)ft_strlen(data->map[x++]) != linelen || (data->map[x][0] != '1'
			|| data->map[x][linelen - 1] != '1'))
			return (-1);
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] != '0' && data->map[x][y] != '1'
				&& data->map[x][y] != 'P' && data->map[x][y] != 'E'
				&& data->map[x][y] != 'C' && data->map[x][y] != 'X')
				return (-1);
			if (data->map[x][y] == 'P')
				define_spawn(data, y, x);
			else if (data->map[x][y] == 'E')
				define_exit(data, y, x);
			else if (data->map[x][y] == 'C')
				data->marker[2]++;
			y++;
		}
	}
	if (data->marker[0] != 1 || data->marker[1] != 1 || data->marker[2] < 1)
		return (-1);
	return (x + 1);
}
