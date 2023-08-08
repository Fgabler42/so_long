/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:36:09 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/08 12:45:30 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"


int main(int arguments, char **string_of_arguments)
{
	char **map_input;

	map_input = check_map(arguments, string_of_arguments);
	if(map_input == NULL)
		return (1);
	if (game_start(map_input))
		return (1);
	free_dubble_array(map_input);

	return (0);
}
