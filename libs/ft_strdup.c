/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:25:22 by fgabler           #+#    #+#             */
/*   Updated: 2023/03/24 16:12:12 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char			*tmp;
	unsigned int	i;

	i = 0;
	tmp = (char *) ft_calloc((ft_strlen(str1) + 1), sizeof (char));
	if (!tmp)
		return (0);
	while (str1[i])
	{
		tmp[i] = str1[i];
		i++;
	}
	return (tmp);
}
