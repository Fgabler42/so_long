/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:36:09 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/29 16:06:20 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"


int main(int arguments, char **string_of_arguments)
{
	check_map(arguments, string_of_arguments);
	/*
	mlx = mlx_init(100, 100, "so_long", true);
	img = mlx_new_image(mlx, 100, 100);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
	*/
	return (0);
}
