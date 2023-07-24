/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgabler <fgabler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:54:19 by fgabler           #+#    #+#             */
/*   Updated: 2023/04/11 12:17:07 by fgabler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	const char	*d;
	const char	*s;
	size_t		dst_len;
	size_t		count;

	d = dst;
	s = src;
	count = dstsize;
	while (count-- != 0 && *dst != '\0')
		dst++;
	dst_len = dst - d;
	count = dstsize - dst_len;
	if (count-- == 0)
		return (dst_len + ft_strlen(src));
	while (*src != '\0')
	{
		if (count != 0)
		{
			*dst++ = *src;
			count--;
		}
		src++;
	}
	*dst = '\0';
	return (dst_len + (src - s));
}
