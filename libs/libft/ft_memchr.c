/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 12:18:41 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/11 14:47:34 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*temp;

	temp = (char *) str;
	while (n--)
	{
		if (*temp == (char) c)
			return ((void *) temp);
		temp++;
	}
	return (NULL);
}
