/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_with_components.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:02:58 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/08 14:28:56 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	fill_with_component(t_game_items *game, char c, mlx_image_t *img);

void	fill_map_with_components(t_game_items *game)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	y = 0;
	while (game->map_input[++i] != NULL)
	{
		j = -1;
		x = 0;
		while (game->map_input[i][++j])
		{
			mlx_image_to_window(game->ptr_to_window, game->space, x, y);
			x += 60;
		}
		y += 60;
	}
	fill_with_component(game, '1', game->wall);
	fill_with_component(game, 'C', game->collectible);
	fill_with_component(game, 'P', game->pacman);
	fill_with_component(game, 'E', game->exit);
}

static void	fill_with_component(t_game_items *game, char c, mlx_image_t *img)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	(void) img;
	while (game->map_input[y] != NULL)
	{
		x = 0;
		while (game->map_input[y][x])
		{
			if (game->map_input[y][x] == c)
			{
				ft_printf("y: %d\n", y);
				ft_printf("x: %d\n", x);
				mlx_image_to_window(game->ptr_to_window, img, x * 60, y * 60);
			}
			x++;
		}
		y++;
	}
}
