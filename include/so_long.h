/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 06:52:43 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/28 16:10:12 by fgabler          ###   ########.fr       */
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

//STRUCTS
typedef struct GameItems
{
	mlx_t					*pointerToWindow;
    char					**map_input;
	int						width;
	int						height;
	int						rumber_of_collectibles;
	int						tmp;
	int						moves;
	mlx_image_t				*pacman;
	mlx_image_t				*collectible;
	mlx_image_t				*wall;
	mlx_image_t				*space;
}   t_game_items;

char **check_map (int arguments, char **string_of_arguments);
int	check_for_two_newlines(char *mapInput);
int	check_walls(char **map);
void	print_map_and_error(char **map, char *str);

#endif
