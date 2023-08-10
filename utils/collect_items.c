/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_items.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 21:37:49 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/10 19:27:57 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	get_smal_box(t_box *box, mlx_instance_t *instances);

void	collect_item(t_game_items *game)
{
	t_box	box_pacman;
	t_box	box_collectible;
	int		collectible_amount;
	int		i;

	collectible_amount = count_component_quantity(game->map_input, 'C');
	i = -1;
	get_smal_box(&box_pacman, &game->pacman->instances[0]);
	while (++i < collectible_amount)
	{
		get_smal_box(&box_collectible, &game->collectible->instances[i]);
		if (box_pacman.up_y >= box_collectible.up_y
			&& )
	}
}

static void	get_smal_box(t_box *box, mlx_instance_t *instances)
{
	box->left_x = (instances->x + 15);
	box->up_y = (instances->y + 15);
	box->right_x = (instances->x + 45);
	box->down_y = (instances->y + 45);
}

