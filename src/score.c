/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 22:43:39 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/04 23:59:04 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/So_Long.h"

void	put_score(t_game *data)
{
	char	*score;
	char	*moves;

	moves = ft_itoa(data->moves);
	score = ft_strjoin("Votre score est : ", moves);
	ft_printf("%s\n", score);
	mlx_string_put(data->win->mlx, data->win->win, 20, 20, 255, score);
	free(score);
	free(moves);
}
