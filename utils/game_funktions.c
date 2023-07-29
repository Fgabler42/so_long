/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_funktions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:55:24 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/30 00:03:14 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static t_game_items	*fill_struct(char **map_input);
static void			get_images(t_game_items *game);

int	game_start(char **map_input)
{
	t_game_items *game;

	game = fill_struct(map_input);
	game->ptr_to_window = mlx_init(game->width, game->height, "GO", 0);
	if (game->ptr_to_window == NULL)
		return (ft_printf("%s\n", mlx_strerror(mlx_errno), 0));
	get_images(game);
	fill_map_with_components(game);
	return (0);
}

static t_game_items	*fill_struct(char **map_input)
{
	t_game_items *game;

	game = malloc(sizeof(t_game_items));
	game->width = ft_strlen(*map_input) * 60;
	game->height = count_doupple_arry_quantity(map_input) * 60;
	game->number_of_collectibles = check_number_of_component(map_input, 'C');
	game->moves = 0;
	game->map_input = map_input;
	return (game);
}

static void	get_images(t_game_items *game)
{
	mlx_texture_t	*space;
	mlx_texture_t	*wall;
	mlx_texture_t	*collectible;
	mlx_texture_t	*pacman;
	mlx_texture_t	*exit;

	space = mlx_load_png("./img/space.c");
	game->space = mlx_texture_to_image(game->ptr_to_window, space);
	mlx_delete_texture(space);
	wall = mlx_load_png("./img/wall.c");
	game->space = mlx_texture_to_image(game->ptr_to_window, wall);
	mlx_delete_texture(wall);
	collectible = mlx_load_png("./img/collectible.c");
	game->space = mlx_texture_to_image(game->ptr_to_window, collectible);
	mlx_delete_texture(collectible);
	pacman = mlx_load_png("./img/pacman.c");
	game->pacman = mlx_texture_to_image(game->ptr_to_window, pacman);
	mlx_delete_texture(pacman);
	exit = mlx_load_png("./img/exit.c");
	game->exit = mlx_texture_to_image(game->ptr_to_window, exit);
	mlx_delete_texture(exit);
}
