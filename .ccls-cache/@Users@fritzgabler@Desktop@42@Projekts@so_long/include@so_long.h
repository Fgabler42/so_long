/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 06:52:43 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/15 16:12:42 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//LIBARYS
# include "../libs/libs.h"
# include <fcntl.h>

# include "../MLX42/include/MLX42/MLX42.h"

//STRUCTS
typedef struct GameItems
{
    mlx_t   *pointerToWindow;
    char    **map_input;
}   game_items;


int check_map (int av, char **ac);

#endif
