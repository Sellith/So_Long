/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 21:39:18 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/04 02:56:41 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/So_Long.h"

static int	defs_win_1(t_window *win)
{
	int	size;

	size = 48;
	win->img[0] = xpm_img(win->mlx, "assets/48x48/waher.xpm", size);
	if (!win->img[0])
		return (0);
	win->img[1] = xpm_img(win->mlx, "assets/48x48/grass.xpm", size);
	if (!win->img[1])
		return (1);
	win->img[2] = xpm_img(win->mlx, "assets/48x48/wtng.xpm", size);
	if (!win->img[2])
		return (2);
	win->img[3] = xpm_img(win->mlx, "assets/48x48/wtng_2.xpm", size);
	if (!win->img[3])
		return (3);
	win->img[4] = xpm_img(win->mlx, "assets/48x48/cherry.xpm", size);
	if (!win->img[4])
		return (4);
	win->img[5] = xpm_img(win->mlx, "assets/48x48/c_door.xpm", size);
	if (!win->img[5])
		return (5);
	win->img[6] = xpm_img(win->mlx, "assets/48x48/o_door.xpm", size);
	if (!win->img[6])
		return (6);
	return (7);
}

static int	defs_win_2(t_window *win)
{
	int	size;

	size = 48;
	win->img[7] = xpm_img(win->mlx, "assets/48x48/mud.xpm", size);
	return (8);
}

static void	ifs(t_game *data, t_window *win, int x, int y)
{
	int	xp;
	int	yp;

	xp = x * 48;
	yp = y * 48;
	if (data->map->map[y][x] == '1')
		mlx_put_image_to_window(win->mlx, win->win, win->img[0], xp, yp);
	else if (data->map->map[y][x] == '0')
		mlx_put_image_to_window(win->mlx, win->win, win->img[1], xp, yp);
	else if (data->map->map[y][x] == 'P')
		mlx_put_image_to_window(win->mlx, win->win, win->img[2], xp, yp);
	else if (data->map->map[y][x] == 'C')
		mlx_put_image_to_window(win->mlx, win->win, win->img[4], xp, yp);
	else if (data->map->map[y][x] == 'E')
	{
		if (data->item == data->map->reachable)
			mlx_put_image_to_window(win->mlx, win->win, win->img[6], xp, yp);
		else
			mlx_put_image_to_window(win->mlx, win->win, win->img[5], xp, yp);
	}
	else if (data->map->map[y][x] == 'X')
		mlx_put_image_to_window(win->mlx, win->win, win->img[7], xp, yp);
}

bool	put_image(t_game *data, t_window *win, char **map)
{
	int	x;
	int	y;

	data->exit_img = defs_win_1(win);
	if (data->exit_img != 7)
		return (ft_printf("img error : %i\n", data->exit_img), false);
	data->exit_img = defs_win_2(win);
	if (data->exit_img != 8)
		return (ft_printf("img error : %i\n", data->exit_img), false);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			ifs(data, win, x, y);
			x++;
		}
		y++;
	}
	return (true);
}

bool	init_window(t_game *data)
{
	int	width;
	int	height;

	width = 48 * data->map->size_line;
	height = 48 * data->map->size_col;
	data->win = malloc(sizeof(t_window));
	if (!data->win)
		return (free(data->map), false);
	data->win->mlx = mlx_init();
	if (!data->win->mlx)
		return (ft_printf("Error: MLX error"), false);
	data->win->win = mlx_new_window(data->win->mlx,
			width, height, "My little Adventure ! First Ride !");
	if (!data->win->win)
		return (ft_printf("Error: MLX error"), false);
	if (!put_image(data, data->win, data->map->map))
		return (false);
	return (true);
}
