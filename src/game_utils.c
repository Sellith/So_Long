/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:36:26 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/04 23:59:10 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/So_Long.h"

void	*xpm_img(void *mlx, char *path, int size)
{
	return (mlx_xpm_file_to_image(mlx, path, &size, &size));
}

int	img_mc(t_game *data, int img, int x, int y)
{
	mlx_put_image_to_window(data->win->mlx, data->win->win,
		data->mv->mc[img], x, y);
	return (0);
}

int	img_scr(t_game *data, int img, int x, int y)
{
	mlx_put_image_to_window(data->win->mlx, data->win->win,
		data->mv->scr[img], x, y);
	return (0);
}

void	mv_release(t_movement *mov)
{
	mov->upc = false;
	mov->downc = false;
	mov->rightc = false;
	mov->leftc = false;
}

void	init_mv(t_movement *mov)
{
	mov->up = 0;
	mov->down = 0;
	mov->right = 0;
	mov->left = 0;
	mv_release(mov);
}
