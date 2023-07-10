/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 14:36:09 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/10 18:08:53 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sotexture_long.h"


int main(int argc, char **argv)
{
	game_items	mlx;
	mlx_texture_to_imag *wall = mlx_load_png("./img/wall.png");
	mlx_texture_to_imag *space = mlx_load_png("./img/space.png");
	mlx_texture_to_imag *pacman = mlx_load_png("./img/pacman.png");
	mlx_texture_to_imag *collectible = mlx_load_png("./img/collectible.png");
	mlx.pointerToWindow = mlx_init(1980, 1080, "test", true);
	if (!mlx.pointerToWindow)
		exit(EXIT_FAILURE);
	mlx_key_hook(mlx, &set_keys, NULL);
	mlx_loop(mlx);
}
