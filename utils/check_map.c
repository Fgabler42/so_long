/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <mail@student.42heilbronn.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:21:52 by fgabler           #+#    #+#             */
/*   Updated: 2023/07/25 20:08:28 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char    *getMapInput(char *PathToFile);
void    free_allocated_array (char **array);
int check_file_type(char **string_of_arguments);

int check_map (int arguments, char **string_of_arguments)
{
	char	*mapInput;
	if (arguments != 2)
		return (1);
    if (check_file_type(string_of_arguments))
		return(1);
	mapInput = getMapInput(string_of_arguments[1]);
    (void) mapInput;
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

char    *getMapInput(char *PathToFile)
{
    int	file_discriptor;
    //char    **mapMatrix;
    char	*storeMapInput;
	char	*storeLineInput;

    file_discriptor = open(PathToFile, O_RDONLY);
	if(file_discriptor < 0)
		return(NULL);
	storeLineInput = get_next_line(file_discriptor);
	while(storeLineInput != NULL)
	{
		storeMapInput = ft_strjoin_mod(storeMapInput, storeLineInput);
		free(storeLineInput);
		storeLineInput = get_next_line(file_discriptor);
        if (storeLineInput == NULL)
            break ;
	}
    ft_printf("%s", storeMapInput);
	return ("hello");
}
