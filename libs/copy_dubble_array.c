/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_dubble_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:47:56 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/13 21:13:45 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**copy_dubble_array(char **array)
{
	int		y;
	char	**new_array;

	y = 0;
	new_array = malloc(
			sizeof(array) * (count_doupple_arry_quantity(array) + 1));
	while (array[y] != NULL)
	{
		new_array[y] = ft_strdup(array[y]);
		y++;
	}
	new_array[y] = NULL;
	return (new_array);
}
