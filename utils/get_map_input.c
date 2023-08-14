/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 12:42:47 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/14 15:02:17 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**get_map_input(char *path_to_file)
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
	if (store_line_input == NULL)
		return (NULL);
	while (store_line_input != NULL)
	{
		if (store_line_input[0] == '\n')
			return (free(store_line_input), NULL);
		map_input = ft_strjoin_mod(map_input, store_line_input);
		free(store_line_input);
		store_line_input = get_next_line(file_discriptor);
		if (store_line_input == NULL)
			break ;
	}
	free(store_line_input);
	map_matrix = ft_split(map_input, '\n');
	return (free(map_input), map_matrix);
}
