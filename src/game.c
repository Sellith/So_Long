/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 22:11:50 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/04 23:30:08 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/So_Long.h"

static void	tile_man(t_game *data, int x, int y)
{
	if (data->map->map[data->player[1] + y][data->player[0] + x] == 'C')
	{
		data->item++;
		ft_printf("Item collected %i / %i\n", data->item, data->map->reachable);
	}
	if (data->map->map[data->player[1] + y][data->player[0] + x] == 'X')
		quit_lose(data);
	if (data->player[0] == data->map->exit[0]
		&& data->player[1] == data->map->exit[1])
		data->map->map[data->player[1]][data->player[0]] = 'E';
	else
		data->map->map[data->player[1]][data->player[0]] = '0';
}

static void	move(t_game *data, int x, int y)
{
	if (data->map->map[data->player[1] + y][data->player[0] + x] != '1')
	{
		tile_man(data, x, y);
		data->moves++;
		data->player[0] += x;
		data->player[1] += y;
		data->map->map[data->player[1]][data->player[0]] = 'P';
		clean_img(data);
		if (!put_image(data, data->win, data->map->map))
			return (exit_w_code(1, data));
	}
	if (data->item == data->map->reachable
		&& data->player[0] == data->map->exit[0]
		&& data->player[1] == data->map->exit[1])
		quit_win(data);
}

static void	keypress(int keysym, t_game *data)
{
	if (keysym == XK_Right || keysym == XK_D || keysym == XK_d)
	{
		data->mv->right++;
		data->mv->rightc = true;
		move(data, 1, 0);
	}
	if (keysym == XK_Left || keysym == XK_A || keysym == XK_a)
	{
		data->mv->left++;
		data->mv->leftc = true;
		move(data, -1, 0);
	}
	if (keysym == XK_Up || keysym == XK_W || keysym == XK_w)
	{
		data->mv->up++;
		data->mv->upc = true;
		move(data, 0, -1);
	}
	if (keysym == XK_Down || keysym == XK_S || keysym == XK_s)
	{
		data->mv->down++;
		data->mv->downc = true;
		move(data, 0, 1);
	}
}

static int	keysel(int keysym, t_game *data)
{
	if (keysym == XK_Escape)
		quit_sl(data);
	else
		keypress(keysym, data);
	return (0);
}

void	events(t_game *data)
{
	mlx_key_hook(data->win->win, &keysel, data);
	mlx_hook(data->win->win, 17, (1L << 17), &quit_sl, data);
	mlx_loop(data->win->mlx);
}
