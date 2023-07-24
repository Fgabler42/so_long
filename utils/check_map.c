/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:21:52 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/24 18:08:08 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


char    *get_input(char *PathToFile);
void    free_allocated_array (char **array);
int check_file_type(char *input);

int check_map (int av, char **ac)
{
    char    *map_input;
	int	a;

	a = av;

    if (check_file_type(ac[1]))
	{
		return(1);
	}
	ft_printf("%d", check_file_type(ac[1]));
    map_input = get_input(*ac);
    return (0); 
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
    store_file_type = ft_split(store_split_path[i - 1], '.');
    free_allocated_array(store_split_path);
    i = 0;
    while (store_file_type[1] != NULL)
        i++;
    if (ft_strncmp(store_file_type[i], "ber", 3)) 
        return (1);
    free_allocated_array(store_file_type);
    return (0);
    
}

void    free_allocated_array (char **array)
{
    int i; 

    i = 0;

    while (array[i] != NULL)
        free(array[i++]);
    free(array); 
}

char    *get_input(char *PathToFile)
{
    int file_discriptor;
//    char **store_map_input;
    file_discriptor = open(PathToFile, O_RDONLY);
	return ("hello");
}
