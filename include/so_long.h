/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 06:52:43 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/13 14:11:10 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define RED			"\x01\033[1;31m\x02"
#define DARK_GREEN	"\x01\033[1;32m\x02"
#define GRASS_GREEN "\x01\033[38;2;0;255;0m\x02"
#define YELLOW		"\x01\033[1;33m\x02"
#define MAGENTA		"\x01\033[1;35m\x02"
#define BLUE		"\x01\033[1;34m\x02"
#define WHITE		"\x01\033[0m\x02"
#define ORANGE		"\x01\033[38;2;255;165;0m\x02"

#define SIZE = 50;

//LIBARYS
# include "../libs/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "stdio.h"

//STRUCTS
typedef struct game_items
{
	mlx_t					*ptr_to_window;
    char					**map_input;
	unsigned int			width;
	unsigned int			height;
	unsigned int			number_of_collectibles;
	unsigned int			tmp;
	unsigned int			moves;
	mlx_image_t				*pacman;
	mlx_image_t				*collectible;
	int						amount_collectible;
	mlx_image_t				*wall;
	mlx_image_t				*space;
	mlx_image_t				*exit;
	mlx_image_t			*player_move_image;
	mlx_texture_t			*texture;
}	t_game_items;

typedef struct box_possitions
{
	int						right_x;
	int						left_x;
	int						up_y;
	int						down_y;
}	t_box;

char	**check_map(int arguments, char **string_of_arguments);
int		check_for_two_newlines(char *map_input);
int		check_walls(char **map);
void	print_map_and_error(char **map, char *str);
int		validate_map_path(char **map);
int		is_component_in_map(char **map, char c);
int		check_number_of_component(char **array, char c);
void	fill_map_with_components(t_game_items *game);
int		game_start(char **map_input);
void	hook_funktions(void *game);
int		walls_check(t_game_items *game, int move_y, int move_x);
void	hook_funktions2(struct mlx_key_data keyData, void *hand_over_struct);
void	collect_item(t_game_items *game);
int		count_component_quantity(char **map, char component);
int		is_packman_touching_box(t_box box_pacman, t_box box_collectible);
void	get_smal_box(t_box *box, mlx_instance_t *instances);
void	end_game(t_game_items *game, t_box pacman_box);
void	show_moves(t_game_items *game);

#endif
