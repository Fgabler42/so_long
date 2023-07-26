/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ingredients_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 09:42:59 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/26 19:13:28 by fgabler          ###   ########.fr       */
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
	while (map[line_amount])
		line_amount++;
	line_amount--;
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

