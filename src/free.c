/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:40:15 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/04 23:36:04 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/So_Long.h"

void	freedarray(char **sent)
{
	int	i;

	i = 0;
	while (sent[i] != NULL)
		free(sent[i++]);
	free(sent);
	sent = NULL;
}

void	clean_img(t_game *data)
{
	int	i;

	i = 0;
	while (data->mv->env[i])
		mlx_destroy_image(data->win->mlx, data->mv->env[i++]);
	i = 0;
	while (data->mv->mc[i])
		mlx_destroy_image(data->win->mlx, data->mv->mc[i++]);
}

void	clean_win(t_window *win)
{
	if (win->win)
		mlx_destroy_window(win->mlx, win->win);
	if (win->mlx)
	{
		mlx_loop_end(win->mlx);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
	}
	free(win);
}
