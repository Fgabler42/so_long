/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:37:49 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/14 12:30:15 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	collect_item(t_game_items *game)
{
	t_box	box_pacman;
	t_box	box_collectible;
	int		i;

	game->amount_collectible = count_component_quantity(game->map_input, 'C');
	i = -1;
	get_smal_box(&box_pacman, &game->pacman->instances[0]);
	while (++i < game->amount_collectible)
	{
		get_smal_box(&box_collectible, &game->collectible->instances[i]);
		if (is_packman_touching_box(box_pacman, box_collectible))
			game->collectible->instances[i].enabled = false;
	}
	end_game(game, box_pacman);
}

void	get_smal_box(t_box *box, mlx_instance_t *instances)
{
	box->left_x = (instances->x + 15);
	box->up_y = (instances->y + 15);
	box->right_x = (instances->x + 45);
	box->down_y = (instances->y + 45);
}

int	is_packman_touching_box(t_box box_pacman, t_box box_collectible)
{
	if ((box_pacman.up_y >= box_collectible.up_y
			&& box_pacman.down_y <= box_collectible.down_y)
		&& (box_pacman.left_x <= box_collectible.left_x
			&& box_pacman.right_x >= box_collectible.right_x))
		return (1);
	return (0);
}
