/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:21:52 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/13 10:43:52 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	**get_map_input(char *path_to_file);
static int	check_file_type(char **string_of_arguments);
static int	is_map_rectangle(char **map);
static int	are_all_ingredients_in_map(char **map_input);

char	**check_map(int arguments, char **string_of_arguments)
{
	char	**map_input;

	if (arguments != 2)
		return (ft_printf("%sMore or less then 2 arguments.\n", RED), NULL);
	if (check_file_type(string_of_arguments))
		return (ft_printf("\n%sWRONG FILETYPE!\n", RED), NULL);
	map_input = get_map_input(string_of_arguments[1]);
	if (map_input == NULL)
		return (print_map_and_error(map_input, "MAP ISN'T VALIDE!\n"), NULL);
	if (are_all_ingredients_in_map(map_input))
		return (ft_printf("%sNOT ALL INGREDIENTS IN MAP.\n", RED), NULL);
	if (is_map_rectangle(map_input))
		return (print_map_and_error(map_input, "MAP ISN'T A RECTANGEL.!\n"),
			free_dubble_array(map_input), NULL);
	if (check_walls(map_input))
		return (print_map_and_error(map_input,
				"WALLS ARE NOT PROPER SET!\nSet a 1 at every outline!\n"),
			free_dubble_array(map_input), NULL);
	if (validate_map_path(map_input))
		return (print_map_and_error(map_input, "MAP PATH IS NOT VALIDE."), NULL);
	return (map_input);
}

static int	check_file_type(char **string_of_arguments)
{
	int	lengs_of_string;

	lengs_of_string = ft_strlen(string_of_arguments[1]);
	if (ft_strncmp((string_of_arguments[1] + (lengs_of_string - 4)), ".ber", 4))
		return (1);
	return (0);
}

static char	**get_map_input(char *path_to_file)
{
	int		file_discriptor;
	char	**map_matrix;
	char	*map_input;
	char	*store_line_input;

	map_input = NULL;
	file_discriptor = open(path_to_file, O_RDONLY);
	if (file_discriptor < 0)
		return (NULL);
	store_line_input = get_next_line(file_discriptor);
	while (store_line_input != NULL)
	{
		map_input = ft_strjoin_mod(map_input, store_line_input);
		free(store_line_input);
		store_line_input = get_next_line(file_discriptor);
		if (store_line_input == NULL)
			break ;
	}
	if (check_for_two_newlines(map_input))
		return (NULL);
	map_matrix = ft_split(map_input, '\n');
	return (free(map_input), map_matrix);
}

static int	is_map_rectangle(char **map)
{
	int	i;

	i = 1;
	while (map[i] != NULL)
	{
		if (ft_strlen(map[0]) != ft_strlen(map[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	are_all_ingredients_in_map(char **map_input)
{
	if (is_component_in_map(map_input, 'C') < 1)
		return (ft_printf("%sLESS THEN 1 COLLECTIBLE.\n", RED), 2);
	if (is_component_in_map(map_input, 'P') != 1)
		return (ft_printf("%sMORE THEN 1 PLAYER.\n", RED), 1);
	if (is_component_in_map(map_input, 'E') != 1)
		return (ft_printf("%sMORE ORE LESS THEN 1 EXIT.\n", RED), 1);
	return (0);
}
