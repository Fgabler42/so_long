/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_funktions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:50:13 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/08 18:59:33 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	handel_movement(t_game_items *game);

void	hook_funktions(void *hand_over_struct)
{
	t_game_items *game;
	game = hand_over_struct;
	handel_movement(game);
}

static void	handel_movement(t_game_items *game)
{

	if (mlx_is_key_down(game->ptr_to_window, MLX_KEY_ESCAPE))
		mlx_close_window(game->ptr_to_window);
	if (mlx_is_key_down(game->ptr_to_window, MLX_KEY_S))
		if (walls_up(game))
			game->pacman->instances[0].y -= 5;
}
