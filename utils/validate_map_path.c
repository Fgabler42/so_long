/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:35:43 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/12 20:47:04 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	get_player_position(char **map, int *x, int *y);
static void	fill_map_to_check(char **copied_map, int y, int x);
static int	check_valid_path(char **copied_map);

int	validate_map_path(char **map)
{
	int		x;
	int		y;
	char	**copied_array_to_check;

	y = 0;
	x = 0;
	get_player_position(map, &y, &x);
	//print_map_and_error(map, "someting1");
	copied_array_to_check = copy_dubble_array(map);
	//print_map_and_error(copied_array_to_check, "someting2");
	fill_map_to_check(copied_array_to_check, y, x);
	if (check_valid_path(copied_array_to_check))
		return (free_dubble_array(copied_array_to_check), 1);
	return (free_dubble_array(copied_array_to_check), 0);
}

static void	get_player_position(char **map, int *y, int *x)
{
	while (map[*y])
	{
		*x = 0;
		while (map[*y][*x])
		{
			if (map[*y][*x] == 'P')
				return ;
			(*x)++;
		}
		(*y)++;
	}
}

static void	fill_map_to_check(char **copied_map, int y, int x)
{
	if (copied_map[y][x] == '1' || copied_map[y][x] == 'F')
		return ;
	copied_map[y][x] = 'F';
	fill_map_to_check(copied_map, y - 1, x);
	fill_map_to_check(copied_map, y + 1, x);
	fill_map_to_check(copied_map, y, x - 1);
	fill_map_to_check(copied_map, y, x + 1);
}

static int	check_valid_path(char **copied_map)
{
	if (is_component_in_map(copied_map, 'C'))
		return (1);
	if (is_component_in_map(copied_map, 'E'))
		return (1);
	return (0);
}
