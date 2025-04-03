/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:11:50 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/03 16:48:59 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/So_Long.h"

static void	tile_man(t_game *data, int x, int y)
{
	if (data->map->map[data->player[1] + y][data->player[0] + x] == 'C')
	{
		data->item++;
		ft_printf("Item collected %i / %i", data->item, data->map->reachable);
	}
	if (data->map->map[data->player[1] + y][data->player[0] + x] == 'X')
		quit_lose(data);
	if (data->player[0] == data->map->exit[0]
		&& data->player[1] == data->map->exit[1])
		data->map->map[data->player[1]][data->player[0]] = 'E';
	else
		data->map->map[data->player[1]][data->player[0]] = '0';
}

static bool	move(t_game *data, int x, int y)
{
	if (data->map->map[data->player[1] + y][data->player[0] + x] != '1')
	{
		tile_man(data, x, y);
		data->player[0] += x;
		data->player[1] += y;
		data->map->map[data->player[1]][data->player[0]] = 'P';
		clean_img(data);
		if (!put_image(data, data->win, data->map->map))
			return (false);
		data->moves++;
		ft_printf("%i\n", data->moves);
	}
	if (data->item == data->map->reachable
		&& data->player[0] == data->map->exit[0]
		&& data->player[1] == data->map->exit[1])
		quit_win(data);
	return (true);
}

static int	keysel(int keysym, t_game *data)
{
	if (keysym == XK_Right || keysym == XK_D)
		if (!move(data, 1, 0))
			exit_w_code(1, data);
	if (keysym == XK_Left || keysym == XK_A)
		if (!move(data, -1, 0))
			exit_w_code(1, data);
	if (keysym == XK_Up || keysym == XK_W)
		if (!move(data, 0, -1))
			exit_w_code(1, data);
	if (keysym == XK_Down || keysym == XK_S)
		if (!move(data, 0, 1))
			exit_w_code(1, data);
	if (keysym == XK_Escape)
		quit_sl(data);
	return (0);
}

void	events(t_game *data)
{
	mlx_key_hook(data->win->win, &keysel, data);
	mlx_hook(data->win->win, 17, (1L << 17), &quit_sl, data);
	mlx_loop(data->win->mlx);
}
