/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 14:30:26 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/14 12:27:51 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	are_all_collectibles_false(t_game_items *game);

void	end_game(t_game_items *game, t_box pacman_box)
{
	t_box	exit_box;

	get_smal_box(&exit_box, &game->exit->instances[0]);
	if (are_all_collectibles_false(game))
	{
		if (is_packman_touching_box(pacman_box, exit_box))
			mlx_close_window(game->ptr_to_window);
	}
}

static int	are_all_collectibles_false(t_game_items *game)
{
	int	i;

	i = -1;
	while (++i < game->amount_collectible)
	{
		if (game->collectible->instances[i].enabled == true)
			return (0);
	}
	return (1);
}
