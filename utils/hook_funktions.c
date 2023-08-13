/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_funktions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:50:13 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/13 13:57:49 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	hook_funktions(void *hand_over_struct)
{
	t_game_items *game;
	game = hand_over_struct;
	if (mlx_is_key_down(game->ptr_to_window, MLX_KEY_ESCAPE))
		mlx_close_window(game->ptr_to_window);
	if (mlx_is_key_down(game->ptr_to_window, MLX_KEY_S))
		walls_check(game, 5, 0);
	if (mlx_is_key_down(game->ptr_to_window, MLX_KEY_W))
		walls_check(game, -5, 0);
	if (mlx_is_key_down(game->ptr_to_window, MLX_KEY_A))
		walls_check(game, 0, -5);
	if (mlx_is_key_down(game->ptr_to_window, MLX_KEY_D))
		walls_check(game, 0, 5);
	collect_item(game);
	show_moves(game);
}

	void	hook_funktions2(struct mlx_key_data keyData, void *hand_over_struct)
{
	t_game_items *game;
	game = hand_over_struct;
	if (keyData.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->ptr_to_window);
	if (keyData.key == MLX_KEY_S)
		walls_check(game, 5, 0);
	if (keyData.key == MLX_KEY_W)
		walls_check(game, -5, 0);
	if (keyData.key == MLX_KEY_A)
		walls_check(game, 0, -5);
	if (keyData.key == MLX_KEY_D)
		walls_check(game, 0, 5);
	collect_item(game);
}

