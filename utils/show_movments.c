/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_movments.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 10:49:08 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/14 11:47:33 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	show_moves(t_game_items *game)
{
	char	*convertet_moves;
	char	*displayed_string;

	convertet_moves = ft_itoa(game->moves);
	if (game->player_move_image)
		mlx_delete_image(game->ptr_to_window, game->player_move_image);
	displayed_string = ft_strjoin("Moves: ", convertet_moves);
	game->player_move_image = mlx_put_string(
			game->ptr_to_window, displayed_string, 0, 0);
	return (free(displayed_string), free(convertet_moves));
}
