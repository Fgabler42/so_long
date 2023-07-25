/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:21:52 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/25 16:16:21 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


char    *get_input(char *PathToFile);
void    free_allocated_array (char **array);
int check_file_type(char **string_of_arguments);

int check_map (int arguments, char **string_of_arguments)
{
	if (arguments != 2)
		return (1);
    if (check_file_type(string_of_arguments))
		return(1);
    return (0); 
}

int check_file_type(char **string_of_arguments)
{
	int	lengsOfString;
	
	lengsOfString = ft_strlen(string_of_arguments[1]);
	if(ft_strncmp((string_of_arguments[1] + (lengsOfString - 4)), ".ber", 4))
		return (1);
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
