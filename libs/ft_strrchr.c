/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 11:03:43 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/06 19:34:30 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	find;

	i = 0;
	i = ft_strlen(str);
	find = (char) c;
	while (i >= 0)
	{
		if (str[i] == find)
		{
			return ((char *) str + i);
		}
		i--;
	}
	return (NULL);
}
