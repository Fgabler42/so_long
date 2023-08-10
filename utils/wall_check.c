/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:29:04 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/10 18:35:04 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_box	get_corners_of_block(mlx_instance_t *instances, int move_y, int move_x);

int	walls_check(t_game_items *game, int move_y, int move_x)
{
	t_box box;

	box = get_corners_of_block(&game->pacman->instances[0], move_y, move_x);
	if (!game->map_input[box.up_y][box.left_x]
		|| game->map_input[box.up_y][box.left_x] == '1'
		|| game->map_input[box.down_y][box.right_x] == '1'
		|| game->map_input[box.up_y][box.right_x] == '1'
		|| game->map_input[box.down_y][box.left_x] == '1')
		return (0);
	else if (game->map_input[box.up_y + 1][box.left_x] == '1'
			|| game->map_input[box.up_y][box.left_x + 1] == '1')
	{
		if (game->map_input[box.up_y + 1][box.left_x] == '1')
			move_y -= ((game->pacman->instances[0].y + move_y) % 60);
		if (game->map_input[box.up_y][box.left_x + 1] == '1')
			move_x -= ((game->pacman->instances[0].x + move_x) % 60);
	}
	game->pacman->instances[0].x += move_x;
	game->pacman->instances[0].y += move_y;
		return (0);
	return (1);
}

static t_box	get_corners_of_block(mlx_instance_t *instances, int move_y, int move_x)
{
	t_box box;

	box.left_x = (instances->x + move_x) / 60;
	box.right_x = (instances->x + move_x + 59) / 60;
	box.up_y = (instances->y + move_y) / 60;
	box.down_y = (instances->y + move_y + 59) / 60;
	return (box);
}
