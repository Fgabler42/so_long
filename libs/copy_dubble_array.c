/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_dubble_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:47:56 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/29 20:50:21 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**copy_dubble_array(char **array)
{
	int		y;
	char	**new_array;

	y = 0;
	new_array = malloc(sizeof(array) * sizeof(*array));
	while (array[y] != NULL)
	{
		new_array[y] = ft_strdup(array[y]);
		y++;
	}
	new_array[y] = NULL;
	return (new_array);
}
