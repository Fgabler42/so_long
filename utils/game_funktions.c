/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_funktions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:55:24 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/14 14:46:21 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_game_items	*fill_struct(char **map_input);
static void			get_images(t_game_items *game);

int	game_start(char **map_input)
{
	t_game_items	*game;

	game = fill_struct(map_input);
	game->ptr_to_window = mlx_init(game->width, game->height, "so_long", 1);
	if (game->ptr_to_window == NULL)
		return (ft_printf("%s\n", mlx_strerror(mlx_errno), 0));
	get_images(game);
	fill_map_with_components(game);
	mlx_loop_hook(game->ptr_to_window, hook_funktions, game);
	mlx_loop(game->ptr_to_window);
	return (0);
}

static t_game_items	*fill_struct(char **map_input)
{
	t_game_items	*game;

	game = malloc(sizeof(t_game_items));
	game->width = ft_strlen(*map_input) * 60;
	game->height = (count_doupple_arry_quantity(map_input)) * 60;
	game->number_of_collectibles = check_number_of_component(map_input, 'C');
	game->moves = 0;
	game->map_input = map_input;
	return (game);
}

static void	get_images(t_game_items *game)
{
	game->texture = mlx_load_png("./img/space.png");
	game->space = mlx_texture_to_image(game->ptr_to_window, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("./img/wall.png");
	game->wall = mlx_texture_to_image(game->ptr_to_window, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("./img/collectible.png");
	game->collectible = mlx_texture_to_image(
			game->ptr_to_window, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("./img/pacman.png");
	game->pacman = mlx_texture_to_image(game->ptr_to_window, game->texture);
	mlx_delete_texture(game->texture);
	game->texture = mlx_load_png("./img/exit.png");
	game->exit = mlx_texture_to_image(game->ptr_to_window, game->texture);
	mlx_delete_texture(game->texture);
}
