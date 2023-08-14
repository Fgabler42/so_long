/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ingredients_check02.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 16:42:05 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/14 17:26:26 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	something_other_than_valide_ingredients(char **map_input);

int	are_all_ingredients_in_map(char **map_input)
{
	if (count_component_quantity(map_input, 'C') < 1)
		return (ft_printf("%sError\nLESS THEN 1 COLLECTIBLE.\n", RED), 2);
	if (count_component_quantity(map_input, 'P') != 1)
		return (ft_printf("%sError\nMORE  OR LESS THEN 1 PLAYER.\n", RED), 1);
	if (count_component_quantity(map_input, 'E') != 1)
		return (ft_printf("%sError\nMORE ORE LESS THEN 1 EXIT.\n", RED), 1);
	if (something_other_than_valide_ingredients(map_input))
		return (ft_printf("%sError\nINVALIDE INGREDIENTS.\n", RED), 1);
	return (0);
}

static int	something_other_than_valide_ingredients(char **map_input)
{
	int	x;
	int	y;

	y = -1;
	while (map_input[++y] != NULL)
	{
		x = -1;
		while (map_input[y][++x])
		{
			if (!((map_input[y][x] == '0')
				|| (map_input[y][x] == 'C')
				|| (map_input[y][x] == '1')
				|| (map_input[y][x] == 'P')
				|| (map_input[y][x] == 'E')))
				return (1);
		}
	}
	return (0);
}
