/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:40:15 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/03 02:59:47 by lvan-bre         ###   ########.fr       */
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
	while (i < data->exit_img && data->win->img[i])
		mlx_destroy_image(data->win->mlx, data->win->img[i++]);
}
