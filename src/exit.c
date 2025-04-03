/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:28:26 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/03 16:53:08 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/So_Long.h"

void	exit_w_code(int code, t_game *data)
{
	if (data->map)
	{
		if (data->map->map)
			freedarray(data->map->map);
		if (data->map->mapfd != -1)
			close(data->map->mapfd);
		free(data->map);
	}
	clean_img(data);
	if (data->win)
	{
		if (data->win->win)
			mlx_destroy_window(data->win->mlx, data->win->win);
		if (data->win->mlx)
		{
			mlx_loop_end(data->win->mlx);
			mlx_destroy_display(data->win->mlx);
			free(data->win->mlx);
		}
		free(data->win);
	}
	exit(code);
}

int	quit_sl(t_game *data)
{
	exit_w_code(0, data);
	return (0);
}

void	quit_win(t_game *data)
{
	ft_printf("\033[96m\n\n\n\t\t\tYOU WIN\n\n\n\033[0m");
	exit_w_code(0, data);
}

void	quit_lose(t_game *data)
{
	ft_printf("\033[93m\n\n\n\t\t\tYOU LOOSE\n\n\n\033[0m");
	exit_w_code(0, data);
}
