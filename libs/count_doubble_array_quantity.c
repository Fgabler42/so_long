/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_doubble_array_quantity.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:11:16 by fgabler           #+#    #+#             */
/*   Updated: 2023/08/12 20:47:44 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_doupple_arry_quantity(char **array)
{
	int	line_quantity;

	line_quantity = 0;
	while (array[line_quantity])
		line_quantity++;
	return (line_quantity);
}
