/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:39:18 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/04 23:31:30 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/So_Long.h"

static void	player_dir_2(t_game *data, int x, int y)
{
	if (data->mv->upc)
	{
		if (data->mv->up % 2 == 0)
			img_mc(data, 4, x, y);
		else
			img_mc(data, 5, x, y);
	}
	else if (data->mv->downc)
	{
		if (data->mv->down % 2 == 0)
			img_mc(data, 6, x, y);
		else
			img_mc(data, 7, x, y);
	}
}

static void	player_dir_1(t_game *data, int x, int y)
{
	if (data->mv->rightc)
	{
		if (data->mv->right % 2 == 0)
			img_mc(data, 0, x, y);
		else
			img_mc(data, 1, x, y);
	}
	else if (data->mv->leftc)
	{
		if (data->mv->left % 2 == 0)
			img_mc(data, 2, x, y);
		else
			img_mc(data, 3, x, y);
	}
	else
		player_dir_2(data, x, y);
}

void	ifs(t_game *data, t_window *win, int x, int y)
{
	int	xp;
	int	yp;

	xp = x * 48;
	yp = y * 48;
	if (data->map->map[y][x] == '1')
		mlx_put_image_to_window(win->mlx, win->win, data->mv->env[0], xp, yp);
	else if (data->map->map[y][x] == '0')
		mlx_put_image_to_window(win->mlx, win->win, data->mv->env[1], xp, yp);
	else if (data->map->map[y][x] == 'P')
		player_dir_1(data, xp, yp);
	else if (data->map->map[y][x] == 'C')
		mlx_put_image_to_window(win->mlx, win->win, data->mv->env[2], xp, yp);
	else if (data->map->map[y][x] == 'E')
	{
		if (data->item == data->map->reachable)
			mlx_put_image_to_window(win->mlx, win->win,
				data->mv->env[4], xp, yp);
		else
			mlx_put_image_to_window(win->mlx, win->win,
				data->mv->env[3], xp, yp);
	}
	else if (data->map->map[y][x] == 'X')
		mlx_put_image_to_window(win->mlx, win->win, data->mv->env[5], xp, yp);
}

bool	put_first_image(t_game *data, t_window *win, char **map)
{
	int	x;
	int	y;

	data->mv = malloc(sizeof(t_movement));
	init_mv(data->mv);
	img_init(data);
	data->mv->downc = true;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			ifs(data, win, x++, y);
		y++;
	}
	put_score(data);
	mv_release(data->mv);
	data->mv->downc = false;
	return (true);
}

bool	init_window(t_game *data)
{
	int	width;
	int	height;

	width = (48 * data->map->size_line);
	height = (48 * data->map->size_col);
	data->win = malloc(sizeof(t_window));
	data->win->mlx = NULL;
	data->win->win = NULL;
	if (!data->win)
		return (free(data->map), false);
	data->win->mlx = mlx_init();
	if (!data->win->mlx)
		return (ft_printf("Error: MLX error\n"), false);
	data->win->win = mlx_new_window(data->win->mlx,
			width, height, "My little Adventure ! First Ride !");
	if (!data->win->win)
		return (ft_printf("Error: MLX error\n"), false);
	if (!put_first_image(data, data->win, data->map->map))
		return (false);
	return (true);
}
