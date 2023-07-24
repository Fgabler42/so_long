/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:36:09 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/24 14:04:48 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"


int main()
{
	mlx_t	*mlx;
	mlx_image_t	*img;

	mlx = mlx_init(100, 100, "so_long", true);
	img = mlx_new_image(mlx, 100, 100);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_loop(mlx);
}
