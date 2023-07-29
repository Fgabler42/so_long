/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ingredients_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:42:59 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/29 21:06:16 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_for_two_newlines(char *mapInput)
{
	int i;
	
	i = 0;
	while (mapInput[i])
	{
		if (mapInput[i] == '\n' && mapInput[i + 1] == '\n')
			return (1);
		i++;
	}
	
	return (0);
}

int	check_walls(char **map)
{
	int	line_amount;
	int	line_len;
	int	i;

	i = 0;
	line_amount = 0;
	line_len = ft_strlen(map[0]);
	line_amount = count_doupple_arry_quantity(map);
	while (i < line_len)
	{
		if (map[0][i] != '1' || map[line_amount][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < line_amount)
	{
		if (map[i][0] != '1' || map[i][line_len - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	count_component_quantity(char **map, char component)
{
	int	component_quantity;
	int	amount_line;
	int	i;

	component_quantity = 0;
	amount_line = count_doupple_arry_quantity(map);
	while (amount_line)
	{
		i = 0;
		while (map[amount_line][i])
		{
			if (map[amount_line][i] == component)
				component_quantity++;
			i++;
		}
		amount_line--;
	}
	ft_printf("%d", component_quantity);
	return (component_quantity);
}

int	is_component_in_map(char **map, char c)
{
	int x;
	int	y;

	y = -1;
	while (map[++y] != NULL)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == c)
				return (1);
		}
	}	
	return (0);
}
