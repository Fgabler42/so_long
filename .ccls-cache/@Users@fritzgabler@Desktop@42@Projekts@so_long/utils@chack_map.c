/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chack_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:21:52 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/14 16:27:37 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


void    free_allocated_array (char **array);
int check_file_type(char *input);

void    chaeck_map (int av, char **ac)
{
    check_file_type(*ac);
}

int check_file_type(char *input)
{
    int i;
    char    **store_split_path;
    char    **store_file_type;

    i = 0;
    store_split_path = ft_split(input, '/'); 
    
    while(store_split_path[i] != NULL)
        i++;
    i--;
    store_file_type = ft_split(store_split_path[i], '.');
    free_allocated_array(store_split_path);
    ft_printf("%s", store_file_type);
    return (1);
    
}

void    free_allocated_array (char **array)
{
    int i; 

    i = 0;

    while (array[i] != NULL)
        free(array[i++]);
    free(array); 
}
