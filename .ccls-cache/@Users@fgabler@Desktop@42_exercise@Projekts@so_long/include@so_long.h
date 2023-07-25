/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 06:52:43 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/25 12:04:15 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//LIBARYS
# include "../libs/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

//STRUCTS
typedef struct GameItems
{
    mlx_t   *pointerToWindow;
    char    **map_input;
}   game_items;

int check_map (int av, char **ac);

#endif
