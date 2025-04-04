/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-bre <lvan-bre@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:49:49 by lvan-bre          #+#    #+#             */
/*   Updated: 2025/04/04 23:36:19 by lvan-bre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/So_Long.h"

static bool	initall(t_game *data)
{
	data->map = NULL;
	data->pars = NULL;
	data->win = NULL;
	data->mv = NULL;
	data->item = 0;
	data->exit_img = 0;
	data->moves = 0;
	data->kp = false;
	return (true);
}

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc != 2)
		return (ft_putendl_fd("Error: Wrong number of arguments", 2), 1);
	if (!initall(&data))
		return (1);
	if (!map_parsing(&data, argv[1]))
		return (1);
	if (!init_window(&data))
		return (ft_putendl_fd("Error: Display error", 2),
			exit_w_code(1, &data), 1);
	data.player[0] = data.map->spawn[0];
	data.player[1] = data.map->spawn[1];
	events(&data);
	return (0);
}
