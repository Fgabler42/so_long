/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:37:09 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/14 17:24:01 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_file_type(char **string_of_arguments);
static int	is_map_rectangle(char **map);
static int	is_file_content_big_enough(char **map);

char	**check_map(int arguments, char **string_of_arguments)
{
	char	**map_input;

	if (arguments != 2)
		return (ft_printf("%sError\n!= 2 arguments.\n", RED), NULL);
	if (check_file_type(string_of_arguments))
		return (ft_printf("\n%sError\nWRONG FILETYPE!\n", RED), NULL);
	map_input = get_map_input(string_of_arguments[1]);
	if (map_input == NULL)
		return (ft_printf("%sError\nMAP ISN'T VALID!\n", RED), NULL);
	if (is_file_content_big_enough(map_input))
		return (print_map_and_error(map_input, "INVALID DIMENIONS"),
			free_dubble_array(map_input), NULL);
	if (are_all_ingredients_in_map(map_input))
		return (ft_printf("%sNOT ALL INGREDIENTS IN MAP.\n", RED),
			free_dubble_array(map_input), NULL);
	if (is_map_rectangle(map_input))
		return (print_map_and_error(map_input, "MAP ISN'T A RECTANGEL.!\n"),
			free_dubble_array(map_input), NULL);
	if (check_walls(map_input))
		return (print_map_and_error(map_input, "WALLS ARE NOT PROPER SET!\n"),
			free_dubble_array(map_input), NULL);
	if (validate_map_path(map_input))
		return (print_map_and_error(map_input, "MAP PATH IS NOT VALIDE."),
			free_dubble_array(map_input), NULL);
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

static int	is_file_content_big_enough(char **map)
{
	if (count_doupple_arry_quantity(map) < 3
		|| count_doupple_arry_quantity(map) > 22
		|| ft_strlen(map[0]) > 42)
		return (1);
	return (0);
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
