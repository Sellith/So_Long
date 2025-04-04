/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:45:58 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/04 23:29:20 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/So_Long.h"

static int	env_init(t_game *data, int size)
{
	data->mv->env[0] = xpm_img(data->win->mlx, "assets/48x48/waher.xpm", size);
	if (!data->mv->env[0])
		return (0);
	data->mv->env[1] = xpm_img(data->win->mlx, "assets/48x48/grass.xpm", size);
	if (!data->mv->env[1])
		return (1);
	data->mv->env[2] = xpm_img(data->win->mlx, "assets/48x48/cherry.xpm", size);
	if (!data->mv->env[2])
		return (2);
	data->mv->env[3] = xpm_img(data->win->mlx, "assets/48x48/c_door.xpm", size);
	if (!data->mv->env[3])
		return (3);
	data->mv->env[4] = xpm_img(data->win->mlx, "assets/48x48/o_door.xpm", size);
	if (!data->mv->env[4])
		return (4);
	data->mv->env[5] = xpm_img(data->win->mlx, "assets/48x48/mud.xpm", size);
	if (!data->mv->env[5])
		return (5);
	return (6);
}

static int	mc_init(t_game *data, int size)
{
	data->mv->mc[0] = xpm_img(data->win->mlx, "assets/48x48/right_1.xpm", size);
	if (!data->mv->mc[0])
		return (0);
	data->mv->mc[1] = xpm_img(data->win->mlx, "assets/48x48/right_2.xpm", size);
	if (!data->mv->mc[1])
		return (1);
	data->mv->mc[2] = xpm_img(data->win->mlx, "assets/48x48/left_1.xpm", size);
	if (!data->mv->mc[2])
		return (2);
	data->mv->mc[3] = xpm_img(data->win->mlx, "assets/48x48/left_2.xpm", size);
	if (!data->mv->mc[3])
		return (3);
	data->mv->mc[4] = xpm_img(data->win->mlx, "assets/48x48/up_1.xpm", size);
	if (!data->mv->mc[4])
		return (4);
	data->mv->mc[5] = xpm_img(data->win->mlx, "assets/48x48/up_2.xpm", size);
	if (!data->mv->mc[5])
		return (5);
	data->mv->mc[6] = xpm_img(data->win->mlx, "assets/48x48/down_1.xpm", size);
	if (!data->mv->mc[6])
		return (6);
	data->mv->mc[7] = xpm_img(data->win->mlx, "assets/48x48/down_2.xpm", size);
	if (!data->mv->mc[7])
		return (7);
	return (8);
}

void	img_init(t_game *data)
{
	int	size;

	size = 48;
	data->exit_img = env_init(data, size);
	data->mv->env[data->exit_img] = NULL;
	if (data->exit_img != 6)
		return (ft_printf("img error : env : %i\n", data->exit_img),
			exit_w_code(1, data));
	data->exit_img = mc_init(data, size);
	data->mv->mc[data->exit_img] = NULL;
	if (data->exit_img != 8)
		return (ft_printf("img error : mc : %i\n", data->exit_img),
			exit_w_code(1, data));
}

bool	put_image(t_game *data, t_window *win, char **map)
{
	int	x;
	int	y;

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
