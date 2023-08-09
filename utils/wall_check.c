/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:29:04 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/09 20:14:32 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	get_corners_of_block(t_game_items *game, int move_y, int move_x);

int	walls_check(t_game_items *game, int move_y, int move_x)
{
	get_corners_of_block(game, move_y, move_x);
	if (!game->map_input[game->up_y][game->left_x]
		|| game->map_input[game->up_y][game->left_x] == '1'
		|| game->map_input[game->down_y][game->right_x] == '1'
		|| game->map_input[game->up_y][game->right_x] == '1'
		|| game->map_input[game->down_y][game->left_x] == '1')
		return (0);
	else if (game->map_input[game->up_y + 1][game->left_x] == '1'
			|| game->map_input[game->up_y][game->left_x + 1] == '1')
	{
		if (game->map_input[game->up_y + 1][game->left_x] == '1')
			move_y -= ((game->pacman->instances[0].y + move_y) % 60);
		if (game->map_input[game->up_y][game->left_x + 1] == '1')
			move_x -= ((game->pacman->instances[0].x + move_x) % 60);
	}
	game->pacman->instances[0].x += move_x;
	game->pacman->instances[0].y += move_y;
		return (0);
	return (1);
}

static void	get_corners_of_block(t_game_items *game, int move_y, int move_x)
{
	game->left_x = (game->pacman->instances[0].x + move_x) / 60;
	game->right_x = (game->pacman->instances[0].x + move_x + 59) / 60;
	game->up_y = (game->pacman->instances[0].y + move_y) / 60;
	game->down_y = (game->pacman->instances[0].y + move_y + 59) / 60;
}
