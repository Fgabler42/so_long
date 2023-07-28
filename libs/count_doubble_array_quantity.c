/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_doubble_array_quantity.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:11:16 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/28 13:27:58 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_doupple_arry_quantity(char **array)
{
	int	line_quantity;

	line_quantity = 0;
	while (array[line_quantity])
		line_quantity++;
	line_quantity--;
	return (line_quantity);
}
